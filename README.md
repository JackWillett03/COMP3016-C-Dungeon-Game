## Video: 

 

## Controls: 

W – Up 

A – Left 

S – Down 

D – Right 

Spacebar – Attack 

## Dependencies used: 

None other than the standard C++ Library have been used in this project. 

## Game programming patterns: 

Although I do not fully understand them even after looking into them, I believe I have a Factory Method Pattern, as MapSpace uses a static method to associate SpaceType enums with their string representation (eg SpaceType::Player = “@”). This could be seen as this type as it creates objects/symbols based on a certain input type and is therefore effectively a Factory Method Pattern, but it could be made better. As well as this I do have a very simplified state pattern in my nextlevel() function which is a simple version of a state transition that moves the player through different levels by handling the transition logic. To make it a full state pattern I would have to create a separate state class for each level that will hold the behavior and rules for each level allowing switching between. 

## Game mechanics: 

## Movement: 

So, in the play function the game asks first for the player to input their move (image 1). The program then checks that it is valid and if it is not, it tells the player and asks them to re-enter it. If valid it calculates the players new position based on the key they entered, e.g. if a “w” then the player position is set to be moved up 1 space, before then checking if the player can move to that space by calling the function isvalidmove (which checks the space isn’t a monster or wall). If it is decided that the move is valid then the function moveplayer is called (relevant moveplayer code shown in image 3). In moveplayer it searches for the player space (@) and then places the player symbol on the new position and increases the turn counter as it was a successful move and then updates the playerposition to the new maps.  
![image](https://github.com/user-attachments/assets/015a447c-a7d0-43a0-ac20-cad938ccc101)
![image](https://github.com/user-attachments/assets/cc838c0b-ac69-4dc5-b578-8810ac1e8faf)

## Attacking: 
![image](https://github.com/user-attachments/assets/89d025a0-c23a-4da8-a671-39ced5907530)
Firstly the game retrieves the player position and checks each space around it returning what symbol is in each. 

![image](https://github.com/user-attachments/assets/f64f8be5-8515-45d9-a7d3-f1302286e217)
A vector is created to store monsters that are found in the following code and then it iterates through the positions. 

![image](https://github.com/user-attachments/assets/770a3f79-71ef-4edb-8caa-53a7e51ffe62)
It first makes sure the space is within the bounds of the map and then it checks if the space is either a ”G”, ”O” or a ”D” for the 3 monster types. If one is present, it adds it to the list of adjacent monsters after finding its x and y positions. 

![image](https://github.com/user-attachments/assets/3b99cd91-2d4a-4fa2-874a-eb579d18777a)
If no monsters are adjacent, it tells the player such. 

![image](https://github.com/user-attachments/assets/43f0be85-0b21-4f93-9876-126bb15f4862)
![image](https://github.com/user-attachments/assets/b96c8f2b-cf79-4135-a91c-1d4a0743c0ae)
Then finally it sorts the monsters by health so that the one with lowest is attacked first (so that the player can kill one rather than interchanging between the 2). The player then does damage based on the damage set with their current weapon’s damage. (as shown standard does 1 and Sword does 2). It increases the turn counter as the turn has been successful then it checks the targeted monster's health to see if it is dead and should be removed from the map or if it should stay on the map and tell the player they have hit it. 

## Coin pickup: 
![image](https://github.com/user-attachments/assets/c50c6255-e1a1-408b-8a52-37f07f557b53)
In moveplayer if the space the player is moving to is a coin (C) then it adds 1 to the coin counter.







