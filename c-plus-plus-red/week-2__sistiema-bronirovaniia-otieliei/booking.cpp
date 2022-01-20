#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <utility>

#include "profile.h"
#include "test_runner.h"

using namespace std;

struct BookingRequest {
    int64_t time;
    int client_id;
    int rooms_count;
};

class Booking {
public:
    Booking() {}
    void Book(int64_t time, const string& hotel, int client_id, int rooms_count) {
        int hotel_id = GetOrCreateHotelId(hotel);
        current_time_ = time;

        BookingRequest req{time, client_id, rooms_count};
        queue<BookingRequest>& booking_requests = hotels_booking_requests_[hotel_id];
        booking_requests.push(req);
        IncreaseClientBookingsCount(hotel_id, client_id);
        IncreaseBookedRoomsCount(hotel_id, rooms_count);
    }

    int Clients(const string& hotel) {
        int hotel_id = GetOrCreateHotelId(hotel);
        UpdateQueueTail(hotel_id, current_time_);
        return hotels_clients_bookings_count_[hotel_id].size();
    }

    int64_t Rooms(const string& hotel) {
        int hotel_id = GetOrCreateHotelId(hotel);
        UpdateQueueTail(hotel_id, current_time_);
        return hotels_booked_rooms_count_[hotel_id];
    }

private:
    int64_t current_time_;
    map<string, int> hotel_ids_;
    int max_hotel_id_ = -1;
    map<int, queue<BookingRequest>> hotels_booking_requests_;
    map<int, map<int, int64_t>> hotels_clients_bookings_count_;
    map<int, int64_t> hotels_booked_rooms_count_;

    int GetOrCreateHotelId(const string& hotel) {
        if (hotel_ids_.count(hotel) == 0) {
            max_hotel_id_++;
            hotel_ids_[hotel] = max_hotel_id_;
            InitHotel(max_hotel_id_);
        }

        return hotel_ids_[hotel];
    }

    void InitHotel(int hotel_id) {
        hotels_booking_requests_[hotel_id];
        hotels_clients_bookings_count_[hotel_id];
        hotels_booked_rooms_count_[hotel_id];
    }

    void UpdateQueueTail(int hotel_id, int64_t current_time) {
        queue<BookingRequest>& booking_requests = hotels_booking_requests_[hotel_id];
        int64_t day_ago = current_time - 86400;
        while (!booking_requests.empty() && booking_requests.front().time <= day_ago) {
            BookingRequest& req = booking_requests.front();
            if (req.time <= day_ago) {
                DecreaseClientBookingsCount(hotel_id, req.client_id);
                DecreaseBookedRoomsCount(hotel_id, req.rooms_count);
            }
            booking_requests.pop();
        }
    }

    void IncreaseClientBookingsCount(int hotel_id, int client_id) {
        hotels_clients_bookings_count_[hotel_id][client_id]++;
    }

    void DecreaseClientBookingsCount(int hotel_id, int client_id) {
        hotels_clients_bookings_count_[hotel_id][client_id]--;
        if (hotels_clients_bookings_count_[hotel_id][client_id] == 0) {
            hotels_clients_bookings_count_[hotel_id].erase(client_id);
        }
    }

    void IncreaseBookedRoomsCount(int hotel_id, int rooms_count) {
        hotels_booked_rooms_count_[hotel_id] += rooms_count;
    }

    void DecreaseBookedRoomsCount(int hotel_id, int rooms_count) {
        hotels_booked_rooms_count_[hotel_id] -= rooms_count;
    }
};

void TestOneHotel() {
    string h1 = "Marriott";
    Booking b;
    ASSERT_EQUAL(b.Clients(h1), 0);
    ASSERT_EQUAL(b.Rooms(h1), 0);

    b.Book(10, h1, 1, 2);
    ASSERT_EQUAL(b.Clients(h1), 1);
    ASSERT_EQUAL(b.Rooms(h1), 2);
    b.Book(20, h1, 2, 3);
    ASSERT_EQUAL(b.Clients(h1), 2);
    ASSERT_EQUAL(b.Rooms(h1), 5);
    b.Book(86400+15, h1, 3, 4);
    ASSERT_EQUAL(b.Clients(h1), 2);
    ASSERT_EQUAL(b.Rooms(h1), 7);
    b.Book(86400*3, h1, 4, 5);
    ASSERT_EQUAL(b.Clients(h1), 1);
    ASSERT_EQUAL(b.Rooms(h1), 5);
}

void TestOneHotelOneClient() {
    string h1 = "Marriott";
    Booking b;
    ASSERT_EQUAL(b.Clients(h1), 0);
    ASSERT_EQUAL(b.Rooms(h1), 0);

    b.Book(10, h1, 1, 2);
    ASSERT_EQUAL(b.Clients(h1), 1);
    ASSERT_EQUAL(b.Rooms(h1), 2);
    b.Book(12, h1, 1, 2);
    ASSERT_EQUAL(b.Clients(h1), 1);
    ASSERT_EQUAL(b.Rooms(h1), 4);
    b.Book(15, h1, 1, 2);
    ASSERT_EQUAL(b.Clients(h1), 1);
    ASSERT_EQUAL(b.Rooms(h1), 6);
    b.Book(15, h1, 1, 2);
    ASSERT_EQUAL(b.Clients(h1), 1);
    ASSERT_EQUAL(b.Rooms(h1), 8);
    b.Book(20, h1, 1, 3);
    ASSERT_EQUAL(b.Clients(h1), 1);
    ASSERT_EQUAL(b.Rooms(h1), 11);
    b.Book(86400+15, h1, 1, 4);
    ASSERT_EQUAL(b.Clients(h1), 1);
    ASSERT_EQUAL(b.Rooms(h1), 7);
    b.Book(86400*3, h1, 1, 5);
    ASSERT_EQUAL(b.Clients(h1), 1);
    ASSERT_EQUAL(b.Rooms(h1), 5);
}

void TestTwoHotels() {
    string h1 = "Marriott";
    string h2 = "FourSeasons";
    Booking b;
    ASSERT_EQUAL(b.Clients(h1), 0);
    ASSERT_EQUAL(b.Rooms(h1), 0);
    ASSERT_EQUAL(b.Clients(h2), 0);
    ASSERT_EQUAL(b.Rooms(h2), 0);

    b.Book(10, h1, 1, 2);
    ASSERT_EQUAL(b.Clients(h1), 1);
    ASSERT_EQUAL(b.Rooms(h1), 2);
    ASSERT_EQUAL(b.Clients(h2), 0);
    ASSERT_EQUAL(b.Rooms(h2), 0);

    b.Book(20, h1, 2, 3);
    ASSERT_EQUAL(b.Clients(h1), 2);
    ASSERT_EQUAL(b.Rooms(h1), 5);
    ASSERT_EQUAL(b.Clients(h2), 0);
    ASSERT_EQUAL(b.Rooms(h2), 0);

    b.Book(86400+15, h2, 3, 4);
    ASSERT_EQUAL(b.Clients(h1), 1);
    ASSERT_EQUAL(b.Rooms(h1), 3);
    ASSERT_EQUAL(b.Clients(h2), 1);
    ASSERT_EQUAL(b.Rooms(h2), 4);

    b.Book(86400+15, h1, 4, 5);
    ASSERT_EQUAL(b.Clients(h1), 2);
    ASSERT_EQUAL(b.Rooms(h1), 8);
    ASSERT_EQUAL(b.Clients(h2), 1);
    ASSERT_EQUAL(b.Rooms(h2), 4);

    b.Book(86400*2+15, h2, 5, 1);
    ASSERT_EQUAL(b.Clients(h1), 0);
    ASSERT_EQUAL(b.Rooms(h1), 0);
    ASSERT_EQUAL(b.Clients(h2), 1);
    ASSERT_EQUAL(b.Rooms(h2), 1);
}

void TestLargeTimeNumber() {
    string h1 = "Marriott";
    Booking b;
    ASSERT_EQUAL(b.Clients(h1), 0);
    ASSERT_EQUAL(b.Rooms(h1), 0);

    b.Book(1'000'000'000'000'000, h1, 1, 2);
    ASSERT_EQUAL(b.Clients(h1), 1);
    ASSERT_EQUAL(b.Rooms(h1), 2);
}

void TestLargeRoomsNumber() {
    string h1 = "Marriott";
    Booking b;
    ASSERT_EQUAL(b.Clients(h1), 0);
    ASSERT_EQUAL(b.Rooms(h1), 0);

    const int64_t max_client_id = 1'000;
    const int64_t max_rooms_count = 1'000'000'000;
    int64_t expected_rooms_count;
    int64_t booking_time;

    for (int i=1; i<=max_client_id; i++) {
        expected_rooms_count = i * max_rooms_count;
        booking_time = 10;
        b.Book(booking_time, h1, i, max_rooms_count);
        ASSERT_EQUAL(b.Clients(h1), i);
        ASSERT_EQUAL(b.Rooms(h1), expected_rooms_count);
    }

    b.Book(86400+15, h1, 1, 1);
    ASSERT_EQUAL(b.Clients(h1), 1);
    ASSERT_EQUAL(b.Rooms(h1), 1);
}

void TestAll() {
    TestRunner tr;
    RUN_TEST(tr, TestOneHotel);
    RUN_TEST(tr, TestOneHotelOneClient);
    RUN_TEST(tr, TestTwoHotels);
    RUN_TEST(tr, TestLargeTimeNumber);
    RUN_TEST(tr, TestLargeRoomsNumber);
}

int main() {
    // Для ускорения чтения данных отключается синхронизация
    // cin и cout с stdio,
    // а также выполняется отвязка cin от cout
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

//    TestAll();

    Booking booking;

    int query_count;
    cin >> query_count;

    {
//        LOG_DURATION("Total")
        for (int query_id = 0; query_id < query_count; ++query_id) {
            string query_type;
            cin >> query_type;

            if (query_type == "BOOK") {
                int64_t time;
                int client_id, rooms_count;
                string hotel;
                cin >> time >> hotel >> client_id >> rooms_count;
                booking.Book(time, hotel, client_id, rooms_count);
            } else if (query_type == "CLIENTS") {
                string hotel;
                cin >> hotel;
                cout << booking.Clients(hotel) << "\n";
            } else if (query_type == "ROOMS") {
                string hotel;
                cin >> hotel;
                cout << booking.Rooms(hotel) << "\n";
            }
        }
    }
    return 0;
}