# Error notifications / Сообщения об ошибках

**0.4.0-alpha:** виджет показывает ошибки, успехи и предупреждения. Актуальное поведение и проверки описаны в [Notifications](NOTIFICATIONS.md). Ниже сохранено первоначальное поведение версии 0.3.0-alpha.

## Русский

Ошибки редактора показываются в отдельном виджете с заголовком «Ошибка», красным акцентом, многострочным текстом и кнопкой ×. В обычном окне он расположен внизу области мира по центру. При недостатке места в области используется экранное размещение. Подсказки управления и сообщения об успешных действиях остаются в боковых панелях.

- В виджет направлены ошибки чисел и допустимых пределов, создания предметов/опор, неподдерживаемого преобразования опоры и записи XML.
- Кнопка × закрывает сообщение. Следующее информационное сообщение после успешного действия также очищает ошибку; переключение в режим персонажа убирает её.
- Виджет сохраняет выбранный объект. Его видимая область исключается из выбора и редактирования мира, включая щелчок по кнопке закрытия.
- Ошибки формата числа показываются при завершении ввода, выход за допустимые пределы — сразу. Последняя корректная поза предмета сохраняется.

Проверка от 16 ноября 2026 года: **271 техническая проверка прошла** в миссии без упаковки с русским интерфейсом, включая **4 проверки виджета ошибок**: читаемое сообщение и сохранение позы, закрытие и восстановление ввода по миру, ошибка числа и её очистка после исправления, ошибка создания без появления лишнего предмета. Этот же клиент оставлен открытым для автора; завершение процесса не проверялось. Визуальную проверку выполняет автор, английский интерфейс проверяется перед релизом в Workshop.

Для самостоятельной проверки выбери предмет, введи `abc` в координату X и щёлкни «Тонкая настройка», чтобы завершить ввод. Внизу появится сообщение об ошибке. Закрой его кнопкой ×; выбранный предмет должен сохраниться. Затем проверь корректный ввод числа.

## English

Editor errors appear in a dedicated notification with an Error heading, red accent, wrapped text and a close button. It sits at the bottom center of the world editing area when space permits, with a screen-based fallback for narrow areas. Sidebar text retains control hints and successful-action messages.

Numeric validation and range errors, object creation and anchor errors, unsupported anchor transforms and XML write failures use the notification. Closing it preserves selection, and its visible area blocks world editing underneath. Subsequent informational messages clear the previous error; entering character mode also clears it. Incomplete numeric input retains its existing validation behavior and the last valid item pose.

On 16 November 2026, **271 technical checks passed** in an unpacked Russian mission, including **4 error-notification checks** covering readable content, pose/selection preservation, close/input behavior, numeric correction and creation failure without extra entities. The same client remains open for author review; shutdown was not validated. Visual inspection is left to the author, and English runtime validation is deferred until the Workshop release.
