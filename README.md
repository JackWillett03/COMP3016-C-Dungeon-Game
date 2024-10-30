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

