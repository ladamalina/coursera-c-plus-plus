/*
 * Вам дана функция string AskTimeServer(). Используя функцию AskTimeServer, напишите класс TimeServer.
 */

#include <iostream>
#include <exception>
#include <string>
#include <system_error>

using namespace std;

//string AskTimeServer() {
    /* Для тестирования повставляйте сюда код, реализующий различное поведение этой функии:
       * нормальный возврат строкового значения
       * выброс исключения system_error
       * выброс другого исключения с сообщением.
    */
//}

class TimeServer {
public:
    string GetCurrentTime() {
        // поместим вызов функции AskTimeServer в try-catch блок
        try {
            last_fetched_time = AskTimeServer();
        } catch (const system_error&) {  // ловим только system_error
        }
        // возвращаем значение поля — либо обновлённое, либо нет
        return last_fetched_time;
    }

private:
    string last_fetched_time = "00:00:00";
};

int main() {
    // Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
