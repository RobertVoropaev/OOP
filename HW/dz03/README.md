Нужно запрограммировать один из алгоритмов, использующих стек, на выбор:
1) Проверка правильности скобочного выражения вида "{ ( ) } [ ]"
2) Вычисление выражения, записанного в обратной польской нотации, например "5 3 - 2 *", для простоты считая, что все операнды и результаты операций не длиннее одной цифры. Выражение может быть некорректным (содержать недопустимые символы или не быть правильной ОПН).
 
Стек реализовать независимо двумя способами: на основе связного списка и на основе массива. Интерфейс этих двух стеков должен полностью совпадать. Критерий правильности выполнения: при замене одной реализации стека на другую клиентский код не должен меняться, кроме одной директивы: using namespace static_stack; на using namespace dynamic_stack;
 
Программой должно быть удобно пользоваться и тестировать - в цикле обрабатывать вводимые строки и выдавать ответ.