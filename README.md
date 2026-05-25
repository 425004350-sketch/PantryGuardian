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
├── .gitignore 
├── README.md  
├── pantry_db.txt  
│
├── include/                
│   ├── FoodItem.h          
│   └── PantryManager.h     
│
└── src/                   
    ├── FoodItem.cpp        
    ├── PantryManager.cpp   
    └── main.cpp
## Official project lead:
Domingo, Quirc Edrian
## Data Format 
The system uses a Comma-Separated Values (CSV) text-based structure.
[itemName],[daysToExpiration],[quantity]
Example:
Milk,5,1.5
Apples,12,6
Canned_Tuna,-1,3
Chicken_Breast,1,0.75
## How to Run
Linux or macOS
./PantryGuardian
Windows with MinGW
.\PantryGuardian.exe
## Main Menu
===================================================
         PANTRY GUARDIAN INTERFACE (SDG 12)        
===================================================
 1. [READ]   Check Registered Inventory Stock
 2. [CREATE] Ingest New Supply Batch Record
 3. [UPDATE] Restock & Refresh Expiration Logs
 4. [DELETE] Evict / Purge Active Asset Profile
 5. [SYSTEM] Fast-Forward Simulation Frame (1 Day)
 6. [EXIT]   Commit Transactions and Terminate App
===================================================
Enter command index execution sequence (1-6):
