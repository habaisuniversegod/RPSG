# Change log

Кратко об изменениях, нововведениях и фиксах.

## 2024-03-28

### Добавлено

* Более менее нормальная документация (в [README.md](README.md))

* Максимальный размер стека можно настроить при сборке проекта в файле [CMakeLists.txt](CMakeLists.txt) (параметр EVAL_STACK_MAX_SIZE, по умолчанию 1024)

### Изменено

* Значение сэмпла теперь отсекается (от -1 до 1), что предотващает целочисленное переполнение при приведении к `signed short` при записи в WAV-файл.