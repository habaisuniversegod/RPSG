# RPSG: Reverse Polish Sound Generator (не курва, а потому-что постфиксный)
Короче, так как я поставусил себе линух и флОЧКи тута нет, то генерировать новые саунды Европы для моих пробебриков придётся изворачиваясь и придумывая свои придумки.
**перевод с даунского:** В общем, эта программа предназначена для т. н. *звукового программирования*, тобишь для синтеза звука при помощи программного кода. А вообще, есть целые жанры, посвящённые такой музыке, к примеру тот же *bytebeat*, или как там его. Отсюда сразу следует плюс: *не нужно хранить звуковые семплы и тратить место, если можно хранить инструкцию (программу), как звук создать.* Полезно для тех, кто самоудовлетворяется на демосцены и прочие девиации.

## Как начать?

Первым делом надо собрать проект, а так как я теперь линуксоид, то и инструкция будет для Линукса.

1. Сначала раздобудьте где-нибудь CMake. Я хз, идёт ли он с каими-то дистрибутивами сразу, но лично я из магазина Debian что-то скачал, там гайды сами найдёте.

2. Зайдите в терминал и готовьтесь копипастить следующие команды: сначала создайте каталог, где эту парашу и будем собирать.

    habaisuniversegod@habacomp:~$ mkdir rpsg
    habaisuniversegod@habacomp:~/rpsg$

