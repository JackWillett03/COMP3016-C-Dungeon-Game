## Video: 

 

## Controls: </br>

W – Up </br>

A – Left </br>

S – Down </br>

D – Right </br>

Spacebar – Attack </br>

## Dependencies used: </br>

None other than the standard C++ Library have been used in this project. </br>

## Game programming patterns: </br>

Although I do not fully understand them even after looking into them, I believe I have a Factory Method Pattern, as MapSpace uses a static method to associate SpaceType enums with their string representation (eg SpaceType::Player = “@”). This could be seen as this type as it creates objects/symbols based on a certain input type and is therefore effectively a Factory Method Pattern, but it could be made better. As well as this I do have a very simplified state pattern in my nextlevel() function which is a simple version of a state transition that moves the player through different levels by handling the transition logic. To make it a full state pattern I would have to create a separate state class for each level that will hold the behavior and rules for each level allowing switching between.  </br>

## Game mechanics:  </br> 

## Movement:  </br>

So, in the play function the game asks first for the player to input their move (image 1). The program then checks that it is valid and if it is not, it tells the player and asks them to re-enter it. If valid it calculates the players new position based on the key they entered, e.g. if a “w” then the player position is set to be moved up 1 space, before then checking if the player can move to that space by calling the function isvalidmove (which checks the space isn’t a monster or wall). If it is decided that the move is valid then the function moveplayer is called (relevant moveplayer code shown in image 3). In moveplayer it searches for the player space (@) and then places the player symbol on the new position and increases the turn counter as it was a successful move and then updates the playerposition to the new maps.   </br>
![image](https://github.com/user-attachments/assets/015a447c-a7d0-43a0-ac20-cad938ccc101) </br>
![image](https://github.com/user-attachments/assets/cc838c0b-ac69-4dc5-b578-8810ac1e8faf) </br>

## Attacking: </br>
![image](https://github.com/user-attachments/assets/89d025a0-c23a-4da8-a671-39ced5907530) </br> 
Firstly the game retrieves the player position and checks each space around it returning what symbol is in each. </br>

![image](https://github.com/user-attachments/assets/f64f8be5-8515-45d9-a7d3-f1302286e217) </br>
A vector is created to store monsters that are found in the following code and then it iterates through the positions. </br>

![image](https://github.com/user-attachments/assets/770a3f79-71ef-4edb-8caa-53a7e51ffe62) </br>
It first makes sure the space is within the bounds of the map and then it checks if the space is either a ”G”, ”O” or a ”D” for the 3 monster types. If one is present, it adds it to the list of adjacent monsters after finding its x and y positions. </br>

![image](https://github.com/user-attachments/assets/3b99cd91-2d4a-4fa2-874a-eb579d18777a) </br>
If no monsters are adjacent, it tells the player such. </br>

![image](https://github.com/user-attachments/assets/43f0be85-0b21-4f93-9876-126bb15f4862) </br>
![image](https://github.com/user-attachments/assets/b96c8f2b-cf79-4135-a91c-1d4a0743c0ae) </br>
Then finally it sorts the monsters by health so that the one with lowest is attacked first (so that the player can kill one rather than interchanging between the 2). The player then does damage based on the damage set with their current weapon’s damage. (as shown standard does 1 and Sword does 2). It increases the turn counter as the turn has been successful then it checks the targeted monster's health to see if it is dead and should be removed from the map or if it should stay on the map and tell the player they have hit it. </br>

## Coin pickup: </br>
![image](https://github.com/user-attachments/assets/c50c6255-e1a1-408b-8a52-37f07f557b53) </br>
In moveplayer if the space the player is moving to is a coin (C) then it adds 1 to the coin counter.</br>

![image](https://github.com/user-attachments/assets/fa31d657-e59c-4293-a4db-cf1f82cc4c66) </br>
When a player dies but still has lives left it sets the coins back to what they were at the end of the last level or shop if the player spent money in there so that the player cannot purposely die to get more coins. If a player loses all lives coins are reset to 0 as the game resets. </br>

## Monster attacking:  </br>
![image](https://github.com/user-attachments/assets/16ebc07b-8462-4424-a218-7a6bff357649) </br>
Firstly, at the end of both a successful move or attack the game checks whether the turn is a multiple of 3 and if it is it calls the attack functions for the monsters (as they take a turn once every 3 turns).  </br>

![image](https://github.com/user-attachments/assets/fdda4f3d-1e3f-4493-ad66-75c31b25216a)  </br>
The position of each monster is collected and then the surrounding spaces positions are defined. Each is then checked for what symbol they hold. If an adjacent position holds the player (@) then the game checks if the bool hasshield is true or false. If the player doesn’t have a shield, then no damage is absorbed by it as it is not there and the player loses the amount of health that the monster deals in damage, (G does 1, O does 2, D does an instant kill). The player is then informed, and the game is paused until they press enter again. If the playerHealth is reduced to 0 then PlayerDeaths is called to handle what happens next (whether the game is restarted or just the level). </br>

![image](https://github.com/user-attachments/assets/cbbdba22-b839-41f5-837f-97e51b795882) </br>
On the other hand, if the player has a shield, the shield will lose health if at full when attacked by G as it has 2 health, and G does 1 damage whereas if the shield only has 1 health it will be destroyed. However, if it's MonsterO and it has full health it is destroyed (as it does 2 damage) and if it has 1 then it destroys the shield and damages the player. D still just kills the player. </br>

## Monster movement: </br>
![image](https://github.com/user-attachments/assets/365458b8-762b-4a90-b424-0cd9470321d8) </br>
So MonsterO is the only one that can move. Firstly, as normal it checks the adjacent positions and checks if one is a player. However, this time if there is a player it sets playeradjacent as true (naturally its false). If it is true, it continues on with the attack as normal. If it is still false, then it skips the attacking and goes onto the following. </br>

![image](https://github.com/user-attachments/assets/e6bd093b-b9fb-4ee5-b04a-684e52ab03b1) </br>
It first sets the shortest distance as the players row – the monster's row and the player column – the monsters column. It then checks the spaces for possible moves ensuring it is both within the bounds of the map and that the distance it is checking is by moving via the SpaceType EmptySpace (which is the . Symbol). It calculates all the paths distances and if the route it has found is the shortest current route, then it updates the shortest route and sets the best move as the adjacent space in that path. If the bestMove is not the monster's current position, then the current position of the monster will be changed to a ”.” and the position of bestMove will be changed to a ”O” and the monster position will be updated. </br>

## Shop: </br>
![image](https://github.com/user-attachments/assets/66bd6aa4-0c92-4c92-adca-d10fc8b89647) </br>
The values of the current health, lives and coins are output to the console along with all of the things possible to buy in the shop. The number of the item's changes depending on what is avaliable (so that say if the sword has been bought the shop items aren’t ”1,2,4,5” and always stay as consecutive numbers). </br>

![image](https://github.com/user-attachments/assets/01b8e3df-c1da-4f83-9a7b-8a3e898b4aca) </br>
Here is buying health as an example. If the player chooses 1 which corresponds to Health, then if first checks if they have enough coins. If they do not, then it tells them how many coins short they are by taking away their coin count from the required amount. If they do have enough, however, it checks they do not have the maximum health and then removes the cost from their total coins and informs them of their new health otherwise it tells them they already have the maximum.  </br>

![image](https://github.com/user-attachments/assets/cd5842bb-2efc-41de-8e38-05ad5374f99a) </br>
For example, when buying the sword, it sets it to false so that it cannot be bought again as they own it already (this removes it from the shop list, the same happens with the shield as you can only have 1). </br>

![image](https://github.com/user-attachments/assets/9142aed0-27a6-4a81-a4e2-0ef4d29620bd) </br>
Here are some examples of where certain bools are true or false, making different choices mean different things are items are removed from the shop. You can also see upon choosing to exit the shop the loop is broken leaving the shop.  </br>

## Sample screens - game images: </br>


![image](https://github.com/user-attachments/assets/2d2d9116-b1b6-4ebb-a141-39909ecda546) - Example of first level </br>

![image](https://github.com/user-attachments/assets/9e15e6a0-b4f5-411e-b17f-b07cda07c473) - Picked up coin </br>

![image](https://github.com/user-attachments/assets/d13c7293-e12a-439a-930b-5d74238da081)- Shop after level  </br>

 ![image](https://github.com/user-attachments/assets/47a3ebeb-0621-4a0d-9e8a-41c6e636997e) - Hit by monster </br>

 ![image](https://github.com/user-attachments/assets/eddaf86a-754d-4969-aac6-01d12f209fc3) - MonsterO starting place </br>

![image](https://github.com/user-attachments/assets/2a417377-f3cd-4bc5-a9c2-76696d979881) - Monster O moved </br>

![image](https://github.com/user-attachments/assets/1fae90fb-d59c-43a4-84db-0a7c1164cd04) - Buy item from shop </br>

![image](https://github.com/user-attachments/assets/273e1687-e252-40c6-a2fe-872c5bfa0c23) - Attempted to buy sword without the coins </br>

![image](https://github.com/user-attachments/assets/8cb0080e-bdac-441a-9d2e-d0c3008fe2fe) - Shop with sword bought </br>

![image](https://github.com/user-attachments/assets/5bd70832-0cbc-4281-b61d-8f77bde413b5) - Message upon losing lives </br>

## Exception handling and test cases: </br>

![image](https://github.com/user-attachments/assets/9bb47e86-f3dc-4644-b7d4-e6a06464aaa4) </br>
![image](https://github.com/user-attachments/assets/497638d4-99ca-486c-82f3-1d7887e24a0d) </br>
Any other input is accounted for via the if statement where it checks if the input is empty or not ”w,a,s,d” which will lead to the output of the text “Invalid input“. The inputs of space and exit are then accounted for with extra if statements. </br> </br>

![image](https://github.com/user-attachments/assets/41079a21-022f-4a75-8564-85293cf07c6f) </br>
![image](https://github.com/user-attachments/assets/ed54d030-0f0e-4b89-a01e-3588575be223) </br>
Here it is accounted for with an else statement, only yes/y or no/n are valid. (converted to lowercase). The shop also has one of these that outputs “Invalid input” if you do not put in an allowed input. </br> </br>

![image](https://github.com/user-attachments/assets/70c6e4b9-3ccc-4568-82a4-e1667266d934) </br>
![image](https://github.com/user-attachments/assets/065f1cf4-33a4-414d-bf3f-9c7dfd6e9826) </br>
Handles the possibility of health going below 0 </br></br>

![image](https://github.com/user-attachments/assets/39d4f666-eb94-4c0c-8339-537716bb5e19) </br>
![image](https://github.com/user-attachments/assets/5c09890f-16e0-488a-8d46-0fcb3ae07c3c) </br>
Handles the player trying to attack non existent monster </br></br>

![image](https://github.com/user-attachments/assets/c6155938-fcd0-44b1-9963-5bcb83702940) </br>
![image](https://github.com/user-attachments/assets/4df21328-1497-4e4e-aedf-b2d1e562a085) </br>
Makes sure the player can’t walk on wall, monster or outside the map.  </br></br>

## What I have achieved:  </br>

I am happy to have achieved a fun, functioning game with multiple mechanics including enemies that can both move and attack and that calculate what the best response will be. As well as this, this is to my memory my first time using C++ and I am happy that I have managed to create this game in such a short time despite having to learn it from scratch. I have also included a moderate amount of OOP something that I now understand a lot more than I did before I started this project and understand why it would be used with larger projects.  </br>

## What I would do differently:   </br>

Next time I would read the document multiple times before starting so that I would have been using OOP most effectively from the start (for example treating the player as an object as it makes code easier to read and find each part etc) rather than starting to use it more halfway through and then going back and converting my code to adhere to OOP better. As well as this I would do more research into Game programming patterns and try to implement them as I still don’t really understand them.  </br>
 
 



















