#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_STR 10



typedef struct{
  char name[MAX_STR];
  int strenght;
  int armour;
  int health;

}HeroType;



typedef struct{
   int strenght;
   int health;

}PirateType;




typedef struct{
 int numPirates;
 PirateType *pirates[MAX_STR];

}ArrayType;



void popPirate(ArrayType *a);  // removes last pirate in the array

void refreshHero(HeroType* ,HeroType*); // resets the heros health

void fight(HeroType*, PirateType*); // simulates one fight 

int randomInt(int,int); // provides a random integer from a range               

void makePirate(PirateType*); // sets the health and random strenght of a pirate 
void refresh(PirateType *[]); // resets a number of pirates health 

void makeArray(ArrayType *a, PirateType*, PirateType*,
        PirateType*, PirateType*, PirateType*, PirateType*, 
        PirateType*, PirateType*, PirateType*, PirateType*);

// makeArray resets the pirates and then adds them back to the array 


void hundredBattles(ArrayType *a, HeroType *tim, HeroType *har, int *t, int *h
        ,int * , int *p, PirateType*, PirateType*, PirateType*, PirateType*,
        PirateType*, PirateType*, PirateType*, PirateType*, PirateType*,
        PirateType*);
// hundred battles simulates 100 battles 


void battle(ArrayType *a, HeroType *h1, HeroType *h2, int *t, int *h, int *b,
        int *p);
// battle simulates one battle

// see more indepth explanation below  



int main()
{
 
    srand(time(NULL));

// The four counters below track the outcomes of the nundred battles;
    int  timmySurvives;
    int haroldSurvives;
    int    bothSurvive;
    int piratesSurvive;
    

    timmySurvives  = 0; 
    haroldSurvives = 0; 
       bothSurvive = 0;
    piratesSurvive = 0;




    


    HeroType* timmy;
    HeroType* harold;
    
    timmy   = (HeroType *)malloc(sizeof(HeroType));
    harold  = (HeroType *)malloc(sizeof(HeroType));
  
    refreshHero(timmy,harold); // sets the attributes of the two heros 

   

    PirateType*   ptr1;
    PirateType*   ptr2;
    PirateType*   ptr3;
    PirateType*   ptr4;
    PirateType*   ptr5;
    PirateType*   ptr6;
    PirateType*   ptr7;
    PirateType*   ptr8;
    PirateType*   ptr9;
    PirateType*  ptr10;



    ptr1   = (PirateType *)malloc(sizeof(PirateType));
    ptr2   = (PirateType *)malloc(sizeof(PirateType));
    ptr3   = (PirateType *)malloc(sizeof(PirateType));
    ptr4   = (PirateType *)malloc(sizeof(PirateType));
    ptr5   = (PirateType *)malloc(sizeof(PirateType));
    ptr6   = (PirateType *)malloc(sizeof(PirateType));
    ptr7   = (PirateType *)malloc(sizeof(PirateType));
    ptr8   = (PirateType *)malloc(sizeof(PirateType));
    ptr9   = (PirateType *)malloc(sizeof(PirateType));
    ptr10  = (PirateType *)malloc(sizeof(PirateType));
    
    
     
    
    ArrayType a; 
    
    makeArray(&a,ptr1,ptr2,ptr3,ptr4,ptr5,ptr6,ptr7,ptr8,ptr9,ptr10);
    
    hundredBattles(&a, timmy, harold,  &timmySurvives, &haroldSurvives,
            &bothSurvive, &piratesSurvive, ptr1, ptr2, ptr3, ptr4, ptr5,
            ptr6, ptr7, ptr8, ptr9, ptr10);

// dealocating dynamically allocated memory 

    free(timmy) ;
    free(harold);
    free(ptr1)  ;
    free(ptr2)  ;
    free(ptr3)  ;
    free(ptr4)  ;
    free(ptr5)  ;
    free(ptr6)  ;
    free(ptr7)  ;
    free(ptr8)  ;
    free(ptr9)  ;
    free(ptr10) ;
    
     


    return 0;


}





int randomInt(int min, int max){

  return(rand() %(max +1 - min) +min);

}


void  makePirate(PirateType *p){
  
  int rand = randomInt(3,6); // gives a random int between 3 and six 
  p->strenght = rand;
  p->health = 20;
  
  


}
void refresh(PirateType *pirates[MAX_STR]){  
    // calls makePirate on every pirate in an array of pirate pointers 
   //  giving them a new strengh, and resetting there health. 
  for(int i = 0; i<10; i++){
    makePirate(pirates[i]);
  
  }

}

void refreshHero(HeroType *timmy, HeroType *harold){

    // initiallizes hero attributes first call, then resets the health after.
    
    timmy->strenght  =  5;
    timmy->health    = 30;
    timmy->armour    =  5;

    harold->strenght =  7;
    harold->health   = 30;
    harold->armour   =  3;

}




void makeArray(ArrayType *a, PirateType *p1, PirateType *p2,
        PirateType *p3, PirateType *p4, PirateType *p5, PirateType *p6,
        PirateType *p7, PirateType *p8, PirateType *p9, PirateType *p10){

    //  adds the pirates to the back of array, resets health an strenght
    //  then sets numPirates to ten . 

    a->pirates[9]  = p10;
    a->pirates[8]  = p9;
    a->pirates[7]  = p8;
    a->pirates[6]  = p7;
    a->pirates[5]  = p6;
    a->pirates[4]  = p5;
    a->pirates[3]  = p4;
    a->pirates[2]  = p3;
    a->pirates[1]  = p2;
    a->pirates[0]  = p1;
    refresh(a->pirates);   
    a->numPirates = 10;

}

void fight(HeroType *h, PirateType *p){
    // simulates a fight between a hero and a pirate

    while(h->health >0 && p->health>0){
      int tempStrenght    = randomInt(p->strenght,2*p->strenght);  
      int armourDifference = h->armour-tempStrenght; 
    
     // the armour difference is used to see is the hero acutally takes damage
    // , if the difference is negative, we know the pirate will damge the heros 
   // health, if it is positive we know the heros health shouldnt change. 


      p->health= p->health - h->strenght;
     
      if(armourDifference <0 && p->health>0){
          h->health = (h->health) + armourDifference;
      }
        
    
    }
    
    if(h->health > 0){
        h->health+=3;
    }
    
    else{
      h->health = 0;
    }



}

void popPirate(ArrayType *a){
    // removes the last pirate from the pirate array 
   
   int size = a->numPirates-1;

  
   for(int i=size; i<size; i++){
       a->pirates[i] = a->pirates[i+1];
    

   }
   a->numPirates--;
    

}


void battle(ArrayType *a, HeroType *timmy, HeroType *harold, int *timmySurvives, int *haroldSurvives ,int *bothSurvive, int *piratesSurvive){
  
 int fighter = 0; 
 



  while(a->numPirates >0 && (timmy->health>0 || harold->health>0)){
 // iterates until there are no pirates in the array or both heros health is
 //  below zero.
      

      if(fighter%2==0){
      
    // if fighter is even timmy fights if fighter is odd harold fights

          
          fight(timmy,a->pirates[a->numPirates-1]);
          // timmy fights the last pirate in the array 
     
          if(timmy->health>0){
              // if timmys health is above zero remove the pirate
              popPirate(a);

              if(a->numPirates == 0)
                  // checks that there are more pirates to fight 
                  break;
         
          }
          else{
              if(harold->health < 0)
                  // checks if the fighters health is both below zero
                  break;

          }
          fighter+=1;

      
      
      }
      else{
          fight(harold, a->pirates[a->numPirates-1]);

          if(harold->health>0){
              popPirate(a);
              if(a->numPirates == 0)
                  break;
           
          }
          else{           
              if(timmy->health < 0)
                  break;

          }
          fighter+=1;
     
      }
  
  }

  // based on the result of the battle the counters are incremented
  
  if(a->numPirates > 0)
      *piratesSurvive+=1;
 
  if((timmy->health >0) && (harold->health == 0 ))
      *timmySurvives+=1;
  
  if((harold->health >0) && (timmy->health == 0 ))
      *haroldSurvives+=1;

  if((timmy->health >0) && (harold->health > 0 ))
     *bothSurvive+=1;





  
}



// simulates 100 battles in the way specified in the assignement instructions 

void hundredBattles(ArrayType *a, HeroType *timmy, HeroType *harold, 
    int *timmySurvives, int *haroldSurvives, int *bothSurvive, 
    int *piratesSurvive, PirateType *p1, PirateType *p2, PirateType *p3,
    PirateType *p4, PirateType *p5, PirateType *p6, PirateType *p7,
    PirateType *p8, PirateType *p9, PirateType *p10 ){

    for(int i=0; i<100; i++) { 
        battle(a, timmy, harold, timmySurvives, haroldSurvives , bothSurvive,  
                piratesSurvive);

       
       // reset the pirates health and strenght and the heros health
        makeArray(a,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10);
        refreshHero(timmy,harold);
        



    }
    
    printf("Timmy won   : %d times.\n", *timmySurvives );

    printf("Harold won  : %d times.\n", *haroldSurvives );

    printf("Both won    : %d times.\n", *bothSurvive );

    printf("Pirates won : %d times.\n", *piratesSurvive );




}

























