# Number Base Converter

**Project Information:**
- **Course:** Computer Science - Algorithms 1
- **Institution:** FAM (Faculdade de Americana)
- **Type:** Academic Project

## Project Overview

This is a console-based application that converts decimal numbers to different number bases (Binary, Octal, and Hexadecimal). The program uses a menu-driven navigation system to provide an interactive user experience.

## System Architecture

### Main Components

1. **Menu Controller System**
   - Centralized menu management
   - Menu registration and navigation
   - Dynamic menu invocation

2. **Processing Module**
   - Number input collection
   - Base conversion selection
   - Conversion execution

3. **History Module**
   - Stores processing cycles
   - Displays conversion history
   - Tracks multiple processing sessions

4. **Cache System**
   - Stores processing data
   - Manages conversion history
   - Maintains up to 40 processing cycles

## Program Flow

### Initialization
1. Program starts in `main()`
2. Registers all menus (Main, Processing, History, Participants)
3. Invokes Main Menu

### Main Menu Flow
- Displays available options
- User selects an option (1-3) or exits (0)
- Routes to selected menu or exits program

### Processing Flow
1. User specifies quantity of numbers to input
2. User enters decimal numbers (validated)
3. User selects conversion type (Binary/Octal/Hexadecimal)
4. System converts all numbers
5. Sort the results in ascending order, starting from the decimal point.
6. Results are displayed
7. User returns to main menu

### History Flow
- Displays all previous processing cycles
- Shows conversions with their types
- User can return to main menu

### Participants Flow
- Displays group member information
- User returns to main menu

## Key Features

- **Input Validation:** Ensures only positive numbers are accepted
- **Multiple Conversions:** Supports Binary, Octal, and Hexadecimal
- **History Tracking:** Maintains records of all conversions
- **Menu Navigation:** Intuitive menu system with "back" functionality
- **Error Handling:** Validates user input and provides feedback

## Data Structures

- **MenuStruct:** Contains menu name, method pointer, and choice identifier
- **ProcessingData:** Stores input numbers, converted results, and conversion type
- **ConversionType:** Enumeration for Binary, Octal, and Hexadecimal

## Conversion Algorithms

All conversions use the division method:
- **Binary:** Divide by 2, collect remainders
- **Octal:** Divide by 8, collect remainders
- **Hexadecimal:** Divide by 16, collect remainders (0-9, A-F)

The remainders are collected in reverse order to form the final result.

