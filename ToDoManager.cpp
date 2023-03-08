#include <Windows.h>

// Обработчик сообщений окна
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // Регистрация класса окна
    WNDCLASS wc = { };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"ToDoListApp";
    RegisterClass(&wc);

    // Создание окна
    HWND hwnd = CreateWindowEx(0, wc.lpszClassName, L"To-Do List", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 640, 480, NULL, NULL, hInstance, NULL);

    // Компонент "Добавление новой задачи"
    CreateWindow(L"STATIC", L"Добавление новой задачи:", WS_VISIBLE | WS_CHILD,
        10, 10, 200, 20, hwnd, NULL, NULL, NULL);

    CreateWindow(L"STATIC", L"Название задачи:", WS_VISIBLE | WS_CHILD,
        10, 40, 200, 20, hwnd, NULL, NULL, NULL);

    CreateWindow(L"EDIT", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
        10, 70, 200, 20, hwnd, NULL, NULL, NULL);

    CreateWindow(L"BUTTON", L"Добавить задачу", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        10, 100, 200, 20, hwnd, (HMENU)1, NULL, NULL);

    // Компонент "Информация о задачах"
    CreateWindow(L"STATIC", L"Счетчик количества задач:", WS_VISIBLE | WS_CHILD,
        10, 150, 200, 20, hwnd, NULL, NULL, NULL);

    CreateWindow(L"STATIC", L"Добавлено задач:", WS_VISIBLE | WS_CHILD,
        10, 180, 100, 20, hwnd, NULL, NULL, NULL);

    CreateWindow(L"STATIC", L"Максимальное количество задач:", WS_VISIBLE | WS_CHILD,
        10, 210, 200, 20, hwnd, NULL, NULL, NULL);

    CreateWindow(L"STATIC", L"10", WS_VISIBLE | WS_CHILD,
        120, 180, 50, 20, hwnd, NULL, NULL, NULL);

    CreateWindow(L"STATIC", L"10", WS_VISIBLE | WS_CHILD,
        220, 210, 50, 20, hwnd, NULL, NULL, NULL);

    // Компонент "Список всех задач"
    CreateWindow(L"STATIC", L"Список всех задач:", WS_VISIBLE | WS_CHILD,
        250, 10, 200, 20, hwnd, NULL, NULL, NULL);

    CreateWindow(L"BUTTON", L"Выполнить", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 
        460, 40, 160, 20, hwnd, NULL, NULL, NULL);

    CreateWindow(L"BUTTON", L"Удалить", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        460, 70, 160, 20, hwnd, NULL, NULL, NULL);

    HWND hList = CreateWindow(L"LISTBOX", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | LBS_NOTIFY | LBS_HASSTRINGS,
        250, 40, 200, 200, hwnd, NULL, NULL, NULL);

    SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)L"Задача 1");
    SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)L"Задача 2");
    SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)L"Задача 3");

    // Отображение окна
    ShowWindow(hwnd, nCmdShow);

    // Цикл обработки сообщений
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case 1:
            // Обработка нажатия кнопки "Добавить задачу"
            break;
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}
