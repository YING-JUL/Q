You are to write a program that is capable performing the following tasks :

input a name and an id, and store this information in a list (sorted by id)
update the name of the person (in the underlying list) with the given id
delete (from the underlying list) the one with the given id
print the current list (names and ids)
The input "commands" are in one of the following "forms" :

a <name> <id>      // add to the underlying list IN ORDER (smaller-id precedes larger-id)
d <id>             // delete from the underlying list the node with this id
u <id> <name>      // update the name of the node (with its id being <id>) to be <name>
p                  // print the underlying list
q                  // quit
There may be any number of white-spaces between the input "items" (e.g., 'a' is an input item ; <name> is an input item, a white space is either ' ' or '\t' or '\n')

You can assume the following :

A <name> will contain no white-spaces. An <id> must be a valid integer. There are only three kinds of errors:

command error (described below)
repeated id (described below)
no such person (described below)
A command-error will only occur in the first "item" of a command (e.g., the first item of a command is "append" and not 'a' nor 'u' nor 'p' nor 'u' nor 'p')

If there is a command error, then your program should print

Sorry!  There is no such command : xxx!
(good news：only a,d,u,p,q are in the test cases.)
translation: The good news is that the test data does not test for command-errors.

A repeated id error is such that the id of a to-be-added person already exists in the list.

If a "repeated id" error occurs, then your program should print

Sorry!  ID already exists : xxx!
A no such person error is such that the id of a to-be-updated or to-be-deleted person does not exist (in the list).

If a "no such person" error occurs, then your program should print

Sorry!  There is no such person : xxx!
Your program should stop processing when encountering any of the following two cases :

Case 1 : the command 'q' appears
Case 2 : it is END-OF-FILE
Example 1： // simplest, 'p', 'q'

a SamWong 123
a LilyChang 456
a ClarkKirk 789
a Kai-ShekChiang 119
a Yin-ChiuMa 256
a Chang-TingHsieh 725
a GeorgeW.Bush 3838
p
q
output

Kai-ShekChiang 119
SamWong 123
Yin-ChiuMa 256
LilyChang 456
Chang-TingHsieh 725
ClarkKirk 789
GeorgeW.Bush 3838
以上各行之後無space，但有line-return

Example 2： // white-space, 'p', EOF


a SamWong 
123
a 

   LilyChang 456
             a ClarkKirk 789
a Kai-ShekChiang 119
a Yin-ChiuMa 256
a Chang-TingHsieh 725
a GeorgeW.Bush 3838
p
                                   ← no 'q', meets EOF
output

Kai-ShekChiang 119
SamWong 123
Yin-ChiuMa 256
LilyChang 456
Chang-TingHsieh 725
ClarkKirk 789
GeorgeW.Bush 3838
以上各行之後無space，但有line-return

Example 3： // 'q' then 'p'


a SamWong 
123
a 

   LilyChang 456
             a ClarkKirk 789
a Kai-ShekChiang 119
a Yin-ChiuMa 256
a Chang-TingHsieh 725
a GeorgeW.Bush 3838
q
p                             ← should not be processed
output


Example 4： // white space, repeated ID ; 'q'


a SamWong 
123
a 

   LilyChang 456
             a ClarkKirk 789
a Kai-ShekChiang 119
a Yin-ChiuMa 256
a Chang-TingHsieh 725
a Who-AreYou 119
a GeorgeW.Bush 3838
p
q
a Who-AreYou 120
a GeorgeW.Bush 3839
p
output

Sorry!  ID already exists : 119!
Kai-ShekChiang 119
SamWong 123
Yin-ChiuMa 256
LilyChang 456
Chang-TingHsieh 725
ClarkKirk 789
GeorgeW.Bush 3838
以上各行之後無space，但有line-return

Example 5： // white space, update, repeated ID ; EOF


a SamWong 
123
a 

   LilyChang 456
             a ClarkKirk 789
a Kai-ShekChiang 119
a Yin-ChiuMa 256
a Chang-TingHsieh 725
a GeorgeW.Bush 3838
u 119 Who-AreYou
a GeorgeBush 3838
p
output

Sorry!  ID already exists : 3838!
Who-AreYou 119
SamWong 123
Yin-ChiuMa 256
LilyChang 456
Chang-TingHsieh 725
ClarkKirk 789
GeorgeW.Bush 3838
以上各行之後無space，但有line-return

Example 6： // 'q', white space, update, repeated ID


a SamWong 
123
a 

   LilyChang 456
a GeorgeW.Bush 3838
             a ClarkKirk 789   p   q
a Kai-ShekChiang 119
a Yin-ChiuMa 256
a Chang-TingHsieh 725
u 119 Who-AreYou
a GeorgeBush 3838
p
output

SamWong 123
LilyChang 456
ClarkKirk 789
GeorgeW.Bush 3838
以上各行之後無space，但有line-return

Example 7： // white-space, delete, repeated ID, update, add, EOF


a SamWong 
123
a 

   LilyChang 456
             a ClarkKirk 789
a Kai-ShekChiang 119
d 456
a Yin-ChiuMa 256
a Chang-TingHsieh 725
d 999
a SamLin   
   123    
a GeorgeW.Bush 3838
u 123 SamLin
p
output

Sorry!  There is no such person : 999!
Sorry!  ID already exists : 123!
Kai-ShekChiang 119
SamLin 123
Yin-ChiuMa 256
Chang-TingHsieh 725
ClarkKirk 789
GeorgeW.Bush 3838
以上各行之後無space，但有line-return

Suggestions for doing this "small project" :

(At least) specify and implement the following functions :OrderInsert(), Update(), Delete()
hint : just copy from your previous answers. you may or may not need to make some modifications. If there is any modification to make, then it should be just a minor modification.
You can also implement a function named Find()。The purpose of this function is only to check if a given id exists in the current list.
Design your main() carefully, and call the above functions in main()
