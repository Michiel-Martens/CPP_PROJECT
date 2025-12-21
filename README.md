# C++ Project - Chinees Poepen Kaartspel

**Auteur:** Michiel Martens  
**Vak:** C++ Programmeren  
**Repository:** https://github.com/Michiel-Martens/CPP_PROJECT.git

## Vraag 11: working build manual as readme on GitHub

## Projectbeschrijving

Dit is een implementatie van het kaartspel "Chinees Poepen" in C++. Het spel ondersteunt zowel menselijke als AI-spelers. Het project demonstreert geavanceerde C++ technieken zoals object-georiënteerd programmeren, polymorfisme, templates, exception handling, file I/O en meer.

## Vereisten

### Software Vereisten
- **C++ Compiler** met C++17 ondersteuning (GCC 7+, Clang 5+, MSVC 2017+)
- **CMake** versie 3.16 of hoger
- **Qt** versie 5 of 6 (Qt5::Core of Qt6::Core)

### Platform
Het project is getest op:
- Linux (Ubuntu 20.04+)
- Windows 10/11
- macOS (met Qt geinstalleerd via Homebrew)

## Installatie vanaf een Clean PC

### Windows

1. **Installeer Qt:**
   - Download Qt van https://www.qt.io/download-open-source
   - Kies Qt 6.x (of Qt 5.15+)
   - Installeer met Qt Creator (optioneel maar aanbevolen)

2. **Installeer CMake:**
   - Download van https://cmake.org/download/
   - Voeg CMake toe aan PATH tijdens installatie

3. **Clone de repository:**
   ```bash
   git clone https://github.com/Michiel-Martens/CPP_PROJECT.git
   cd CPP_PROJECT/CPP_Project_Michiel_Martens
   ```

4. **Build met CMake:**
   ```bash
   mkdir build
   cd build
   cmake .. -DCMAKE_PREFIX_PATH="C:/Qt/6.x.x/msvc2019_64"  # Pas aan naar jouw Qt pad
   cmake --build . --config Release
   ```

5. **Run het programma:**
   ```bash
   Release\NEWtestCPP_PJ.exe
   ```

### Linux (Ubuntu/Debian)

1. **Installeer dependencies:**
   ```bash
   sudo apt update
   sudo apt install build-essential cmake qt6-base-dev
   # Of voor Qt5:
   # sudo apt install build-essential cmake qtbase5-dev
   ```

2. **Clone de repository:**
   ```bash
   git clone https://github.com/Michiel-Martens/CPP_PROJECT.git
   cd CPP_PROJECT/CPP_Project_Michiel_Martens
   ```

3. **Build met CMake:**
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

4. **Run het programma:**
   ```bash
   ./NEWtestCPP_PJ
   ```

### macOS

1. **Installeer Homebrew** (als nog niet geinstalleerd):
   ```bash
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
   ```

2. **Installeer dependencies:**
   ```bash
   brew install cmake qt@6
   ```

3. **Clone de repository:**
   ```bash
   git clone https://github.com/Michiel-Martens/CPP_PROJECT.git
   cd CPP_PROJECT/CPP_Project_Michiel_Martens
   ```

4. **Build met CMake:**
   ```bash
   mkdir build
   cd build
   cmake .. -DCMAKE_PREFIX_PATH="$(brew --prefix qt@6)"
   make
   ```

5. **Run het programma:**
   ```bash
   ./NEWtestCPP_PJ
   ```

## Gebruik

Na het starten van het programma:

1. Voer het aantal levens per speler in (standaard: 3)
2. Voer het aantal menselijke spelers in
3. Voer het aantal AI-spelers in
4. Voer namen in voor menselijke spelers
5. Het spel start automatisch

### Spelregels
- Elke speler krijgt 3 kaarten
- Spelers kunnen kaarten ruilen met de top kaart van het deck
- Aan het einde van elke ronde verliest de speler met de laagste hand-waarde een leven
- De laatste speler die nog levens heeft, wint

## Projectstructuur

```
CPP_Project_Michiel_Martens/
├── main.cpp              # Entry point (Vraag 2: clean main)
├── Game.h / Game.cpp      # Game logic class
├── PlayerBase.h / .cpp    # Abstract base class (Vraag 18: polymorphism)
├── HumanPlayer.h / .cpp  # Human player implementation
├── AIPlayer.h / .cpp     # AI player implementation
├── Card.h / Card.cpp     # Card class (Vraag 25: templates)
├── Deck.h / Deck.cpp     # Deck class (Vraag 28: unsigned char)
└── CMakeLists.txt        # Build configuration
```

## Geïmplementeerde C++ Features

### OOP Vereisten
- ✅ **Vraag 12-15:** Constructors (default, parameterized, copy) en destructors
- ✅ **Vraag 16:** Member initialization lists
- ✅ **Vraag 17:** Constructor forwarding (delegating constructors)
- ✅ **Vraag 18:** Dynamic polymorphism (virtual functions, abstract base class)
- ✅ **Vraag 19:** Useful usage of `this` pointer
- ✅ **Vraag 20-23:** Member functions, variables, getters/setters
- ✅ **Vraag 24:** Inline functions
- ✅ **Vraag 25:** Template functions (Card.h)
- ✅ **Vraag 26:** Friend function (operator<<)

### C++ Features
- ✅ **Vraag 27:** Namespace (ChinesePoepen)
- ✅ **Vraag 28:** Unsigned char for memory efficiency (Deck.cpp)
- ✅ **Vraag 29-30:** Const references (variables and functions)
- ✅ **Vraag 31:** Boolean usage
- ✅ **Vraag 32-33:** Dynamic memory (unique_ptr)
- ✅ **Vraag 34:** Modern call-by-reference
- ✅ **Vraag 35:** String class usage
- ✅ **Vraag 36:** Container classes (vector)
- ✅ **Vraag 37:** nullptr usage
- ✅ **Vraag 38:** File I/O (saveGame/loadGame in Game.cpp)
- ✅ **Vraag 39:** Exception handling
- ✅ **Vraag 40:** Lambda functions (eliminatePlayers)

### Algemeen
- ✅ **Vraag 1:** Git repository
- ✅ **Vraag 2:** Clean main
- ✅ **Vraag 3:** No globals
- ✅ **Vraag 4:** Correct protections (private/protected/public)
- ✅ **Vraag 5:** Maintainability (comments, naming)
- ✅ **Vraag 6:** Separate header files
- ✅ **Vraag 7:** Complete compiling project
- ✅ **Vraag 9:** Regular git commits
- ✅ **Vraag 11:** Build manual (dit bestand)

## Troubleshooting

### Qt niet gevonden
Als CMake Qt niet kan vinden:
```bash
cmake .. -DCMAKE_PREFIX_PATH="/path/to/Qt/6.x.x/gcc_64"
```

### Build errors
- Zorg dat je C++17 compiler hebt
- Check of alle dependencies geinstalleerd zijn
- Verwijder de build/ folder en probeer opnieuw

### Runtime errors
- Zorg dat Qt libraries in je PATH staan (Windows)
- Op Linux: `export LD_LIBRARY_PATH=/path/to/qt/lib:$LD_LIBRARY_PATH`

## Licentie

Dit project is gemaakt voor educatieve doeleinden.

## Contact

Voor vragen: michiel1.martens@gmail.com
