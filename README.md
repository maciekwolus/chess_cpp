# ♟️ Chess Game in C++ with Qt GUI

This project is a fully functional, GUI-based chess game written in **C++** using the **Qt framework**. It offers a complete chess experience with all standard rules, visual gameplay, and turn-based logic. The application demonstrates strong object-oriented design, modern C++ practices, and clear separation between backend logic and graphical frontend.

---

## Features

- **Complete Chess Logic**
  - Piece-specific move validation
  - Check, checkmate, and stalemate detection
  - Castling and pawn promotion
  - Turn handling and move history tracking

- **Modular OOP Architecture**
  - `Piece` base class with subclasses like `King`, `Queen`, `Rook`, etc.
  - `Board` class for backend logic
  - `pieceOnBoard` class for GUI representation

- **Modern C++ Standards**
  - Smart pointers (`std::unique_ptr`)
  - STL containers (`std::map`, `std::vector`, `std::pair`)
  - Clean, maintainable code structure

- 🖼**Graphical Interface (Qt)**
  - Built with Qt Widgets (`QMainWindow`, `QDialog`, `QGraphicsScene`)
  - Interactive drag-and-drop mechanics
  - Confirmation dialogs (exit, restart, game outcome)

- **Frontend & Backend Sync**
  - Real-time GUI updates linked to backend state
  - Logic-driven animations and board behavior

---

## Getting Started

### Prerequisites
- Qt 5 or 6 (e.g., Qt Creator)
- C++17 or newer
- CMake or QMake (depending on setup)
