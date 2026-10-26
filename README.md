# Tetris 2.0 — SDL3

[English](#english) | [Русский](#русский)

<a id="english"></a>
## English

A more feature-rich Tetris-style game written in C++ with SDL3. Compared with the smaller Tetris project, this version separates the grid, blocks, game logic, colors, and text UI into dedicated source files.

### Features present in the source

- SDL3 application callback structure.
- 10-column by 20-row grid.
- Seven tetromino types with rotation states.
- Left/right movement, downward movement, and rotation.
- Collision checks against the grid and settled blocks.
- Locking pieces into the grid.
- Full-row clearing logic.
- Score tracking, including points for cleared rows and downward movement.
- Preview of the next piece.
- Game-over state and a Space-key restart path in the game logic.
- Text UI implemented with SDL_ttf.

### Controls

| Key | Action |
|---|---|
| Left Arrow | Move the active piece left |
| Right Arrow | Move the active piece right |
| Down Arrow | Move the piece down; the game logic also awards a point for this action |
| Up Arrow | Rotate the active piece |
| Space | Restart after game over, as handled by the game logic |
| Close window | Quit the application |

### Technology

- C++
- SDL3
- SDL_ttf (SDL3_ttf) for text rendering

### Requirements and assets

- A C++ compiler and build setup compatible with the source
- SDL3 development files
- SDL3_ttf development files
- The source refers to the font file `Font/monogram.ttf`. Ensure this asset exists at that relative path when running the program; it was not present in the repository file listing inspected for this README.

### Build and run

The repository contains C++ source and header files, but no ready-to-use build instructions are included here. Configure SDL3 and SDL3_ttf include/library paths for your environment, ensure the font asset is available at `Font/monogram.ttf`, compile the project sources, and link against the required libraries.

The build has not been independently verified as part of this README.

### Project structure

```text
Tetris-2.0/
├── main.cpp       # SDL callbacks, initialization, rendering loop
├── game.hpp/.cpp  # Game state, input, movement, scoring, and reset
├── grid.hpp/.cpp  # Playfield and row operations
├── block.hpp      # Base block behavior
├── blocks.cpp     # Seven tetromino definitions
├── position.hpp/.cpp
├── colors.hpp/.cpp
└── text.hpp/.cpp  # Score, next-piece, and game-over UI text
```

### Current limitations

- Build configuration and dependency setup are not documented in the repository files reviewed for this README.
- The source expects a font at `Font/monogram.ttf`; that file should be included or the path should be configured.
- As with any work in progress, the game should be built and tested in the target environment before being described as a stable release.

### Purpose

This project explores a more modular game architecture, SDL3 rendering and callbacks, tetromino rotation and collision logic, score updates, and text rendering.

---

<a id="русский"></a>
## Русский

Более функциональная игра в стиле Tetris на C++ с использованием SDL3. По сравнению с небольшим проектом Tetris эта версия разделяет игровое поле, фигуры, игровую логику, цвета и текстовый интерфейс по отдельным исходным файлам.

### Возможности, присутствующие в исходном коде

- Структура приложения на callback-функциях SDL3.
- Игровое поле размером 10 столбцов на 20 строк.
- Семь типов тетромино с состояниями поворота.
- Перемещение влево и вправо, движение вниз и поворот.
- Проверка столкновений с границами поля и закреплёнными блоками.
- Фиксация фигур на игровом поле.
- Логика очистки заполненных рядов.
- Подсчёт очков, включая очки за заполненные ряды и движение вниз.
- Предпросмотр следующей фигуры.
- Состояние Game Over и путь перезапуска клавишей Space в игровой логике.
- Текстовый интерфейс с использованием SDL_ttf.

### Управление

| Клавиша | Действие |
|---|---|
| Стрелка влево | Переместить активную фигуру влево |
| Стрелка вправо | Переместить активную фигуру вправо |
| Стрелка вниз | Переместить фигуру вниз; игровая логика также начисляет за это очко |
| Стрелка вверх | Повернуть активную фигуру |
| Space | Перезапустить игру после Game Over согласно игровой логике |
| Закрытие окна | Завершить приложение |

### Технологии

- C++
- SDL3
- SDL_ttf (SDL3_ttf) для отрисовки текста

### Требования и ресурсы

- Компилятор C++ и система сборки, совместимые с исходным кодом
- Файлы разработки SDL3
- Файлы разработки SDL3_ttf
- В исходниках указан шрифт `Font/monogram.ttf`. При запуске файл должен существовать по этому относительному пути; в списке файлов репозитория, проверенном при подготовке README, его не было.

### Сборка и запуск

В репозитории есть исходные файлы C++ и заголовки, но готовая инструкция сборки здесь не представлена. Настройте пути к заголовкам и библиотекам SDL3 и SDL3_ttf, обеспечьте наличие шрифта `Font/monogram.ttf`, скомпилируйте исходники и подключите необходимые библиотеки.

Сборка не проверялась отдельно в рамках подготовки этого README.

### Структура проекта

```text
Tetris-2.0/
├── main.cpp       # Callback-функции SDL, инициализация и цикл отрисовки
├── game.hpp/.cpp  # Состояние игры, ввод, движение, очки и сброс
├── grid.hpp/.cpp  # Игровое поле и операции со строками
├── block.hpp      # Базовое поведение блока
├── blocks.cpp     # Описания семи тетромино
├── position.hpp/.cpp
├── colors.hpp/.cpp
└── text.hpp/.cpp  # Текст счёта, следующей фигуры и Game Over
```

### Текущие ограничения

- Конфигурация сборки и настройка зависимостей не описаны в проверенных файлах репозитория.
- Исходный код ожидает шрифт `Font/monogram.ttf`; этот файл следует добавить или изменить путь к нему.
- Перед тем как считать проект стабильным релизом, необходимо собрать и проверить игру в целевой среде.

### Цель проекта

Изучение более модульной архитектуры игры, рендеринга и callback-функций SDL3, поворота фигур, проверки столкновений, подсчёта очков и вывода текста.
