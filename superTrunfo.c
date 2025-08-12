#include <stdio.h>
#include <stdlib.h>
typedef struct{

    char stateName[50], cityName[50], cardCode[5];
    int id, populationNumber, touristAttractionsNumber;
    float fieldValue, GDPValue, denselyPopulated, GDPPerHead;

} Card;

void bufferClean(void){
    int ch;
    while ((ch = getchar())!='\n'&&ch !=EOF);
}

int main(){

    int qnt;  
        
    printf("Enter Quantity of Cards: ");
    scanf("%d", &qnt);
    
    Card *card =(Card*)malloc(qnt*sizeof(Card));
    
    for(int i = 0; i < qnt; i++){
        printf("Card %d data:", i+1);
        printf("\n");

        card[i].id = i+1;

        printf("State: ");
        scanf(" %49[^\n]", card[i].stateName);
        printf("City: ");
        scanf(" %49[^\n]", card[i].cityName);
        printf("Population: ");
        scanf(" %i", &card[i].populationNumber);
        printf("Number of Tourist Attractions: ");
        scanf(" %i", &card[i].touristAttractionsNumber);
        printf("field: ");
        scanf(" %f", &card[i].fieldValue);
        printf("GDP: ");
        scanf(" %f", &card[i].GDPValue);
        bufferClean();
        printf("Card Code (Only char): ");
        fgets(card[i].cardCode, sizeof(card[i].cardCode), stdin);   
        card[i].denselyPopulated = card[i].populationNumber/card[i].fieldValue;
        card[i].GDPPerHead = card[i].GDPValue/card[i].populationNumber;
        printf("\n");
    }

    for(int i = 0; i < qnt; i++) { 
        printf("Card %d Result:", i+1);
        printf("\n");
        printf("State: %s\n", card[i].stateName);
        printf("City: %s\n", card[i].cityName);
        printf("Population: %i\n", card[i].populationNumber);
        printf("Number of Tourist Attractions: %i\n", card[i].touristAttractionsNumber);
        printf("field: %.2f\n", card[i].fieldValue);
        printf("GDP: %.2f km²\n", card[i].GDPValue);
        printf("Card Code: %s\n", card[i].cardCode);
        printf("Densely Populate: %.2f inhab/km²\n", card[i].GDPValue);
        printf("GDP Per Head: %.2f\n", card[i].GDPValue);
        printf("\n");
    }

return 0;
}