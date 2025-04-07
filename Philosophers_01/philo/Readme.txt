~ Project Name -> PHILOSOPHERS.
~ SHOOL NAME -> 42 Kuala Lumpur.

~ Duration for code -> 2 Weeks.
~ Duration for reserch -> [1]1/2 weeks.

/***
 *     ██▓███   ██░ ██  ██▓ ██▓     ▒█████  
 *    ▓██░  ██▒▓██░ ██▒▓██▒▓██▒    ▒██▒  ██▒
 *    ▓██░ ██▓▒▒██▀▀██░▒██▒▒██░    ▒██░  ██▒
 *    ▒██▄█▓▒ ▒░▓█ ░██ ░██░▒██░    ▒██   ██░
 *    ▒██▒ ░  ░░▓█▒░██▓░██░░██████▒░ ████▓▒░
 *    ▒▓▒░ ░  ░ ▒ ░░▒░▒░▓  ░ ▒░▓  ░░ ▒░▒░▒░ 
 *    ░▒ ░      ▒ ░▒░ ░ ▒ ░░ ░ ▒  ░  ░ ▒ ▒░ 
 *    ░░        ░  ░░ ░ ▒ ░  ░ ░   ░ ░ ░ ▒  
 *              ░  ░  ░ ░      ░  ░    ░ ░  

~Project Demand:

 Okay, let me state the task that philosophers project demands.
So what its about is that, there are five philosophers and one so called
pool of data and what we are tasked to do is that to create a program
to ensure that all the philosophers can eat for the pool of data
in sync  with their forks and without coming to a situation where one philo starves to death.
.Each philo requres two forks to eat.So what are the possible edge casses that we could face,
 One, we call it the deadlock, okay what does a deadlock do, deadlock is when  there is one fork
assigned to each philo, in this case lets say there is 3 philos in a table
with one pool of data, now each philo has been assigned to their concurrent forks
once that is done, and when the process starts each philo will be taking the 
first fork assigned to them, for example:philo one will be assinged fork one, 
thus now all the three philo takes one fork each that are assinged to them, 
but the claus here is that each philo needs at least two forks ot eat, but each
philo only got one now. So now each philo is wating for thier second fork.
Thus this is called a deadlock where no philos can eat not do anything. 

Thus what is the cause of this problem, well if my understading is rigth, in the mid of a 
flight going to india, haha. the cause of this could be becasuse of the usage of mutex
why use the mutex is due to te race condition that i will metion it later, thats actually 
the secodn problem, but anyways the mutex works in a very particular way where, it prevents
two philos from accsessing one fork at the same time, thus the mutex works like a key where
when one philo is holding the fork another cannot take it from them nor snatch.

OKay that is the first case,lets now look at the second case, The second case is called 
the Race condition, 


Lone Philo routine.


 What is a mutex??

	[ Analogy:Mutex = A lock on a bathroom door....]🔐🚪

 ~ Imagine multiple people(threads in this case) wants to use a shared bathroom(fork).
 ~ We put a lock on the door(mutex) so only one person can acsess the bathroom at a time.
 ~ If we forget to add a lock, then multiple people can try and acsess the bathroom
 	at the same time, which may cause chaos(race condition).
 ~ The writing lock ensures that only one person can write on the board(print on the screen)
 	at a time.


What is a race condition??

	[Analogy for the Race-Condition:]

  🏎️ The Fast Food Drive-Thru Analogy 🍔
  Imagine you and your friend pull up to a fast food drive-thru that has two order windows,
  but only one kitchen preparing the food.
 
  1)Scenario 1: No Race Condition (Synchronized Orders) ✅

  ~You pull up first, place your order for a double cheeseburger 🍔,
   and the cashier confirms it before moving on.
   Your friend pulls up next and orders a chicken sandwich 🍗.
   The kitchen receives both orders in the correct order and prepares them properly.
   You get your cheeseburger, your friend gets their chicken sandwich. All good!


  2)Scenario 2: Race Condition (Chaos in the Kitchen) ❌

  ~You and your friend accidentally talk at the same time into the speaker.
   The cashier only hears:
   You: "Double..."
   Friend: "...sandwich"
   The kitchen receives an incomplete/confused order and prepares a random meal.
   The food comes out wrong—you get a chicken cheeseburger you never ordered!

~ init_mutexes is a function that initialises the mutex lock,
  (which are used to prevent the race conditions.)
~ It loops through all the forks and initialises one mutex for each philos.
~ It also initialises a writing_lock mutex, which is most likely used to 
  control the output printing (thus multiple threads dont print at the same
  time and mess up the output).

  / When you pass by reference (&), you keep modifying the original struct.
// When you pass by value, a copy is made, so changes don’t reflect outside.