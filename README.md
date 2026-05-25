# PantryGuardian
## Project Title and SDG Goal
This project supports SDG 12 Responsible Consumption and Production to track perishable items (like food products in a pantry or kitchen) to help prevent waste.
## Project Description
This allows you to see how your pantry will look a few days from now, showing you exactly what is about to spoil so you can prioritize cooking it before it goes to waste.
## Core Features
- Full CRUD Database Lifecycle
- Dynamic Time-Forward Simulation Matrix
- Algorithmic Risk Analytics & Warning Systems
- Dual-Stream Data Persistence (File IO Synchronizer)
## Repository Structure
PantryGuardianProject/
│
├── .gitignore              # Tells Git to ignore temporary/compiled executable files
├── README.md               # Project documentation and setup instructions
├── pantry_db.txt           # The database file generated/loaded by your system
│
├── include/                # HEADER FILES (.h) - The Class blueprints
│   ├── FoodItem.h          
│   └── PantryManager.h     
│
└── src/                    # SOURCE FILES (.cpp) - The actual logic & main entry point
    ├── FoodItem.cpp        
    ├── PantryManager.cpp   
    └── main.cpp
