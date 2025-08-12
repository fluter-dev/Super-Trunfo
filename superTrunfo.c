#include <stdio.h>
#include <stdlib.h>

typedef struct{

    char stateName[50], cityName[50], cardCode[5];
    int id, touristAttractionsNumber;
    long int populationNumber;
    float fieldValue, GDPValue, denselyPopulated, GDPPerHead, SuperPower;

} Card;

void bufferClean(void){
    int ch;
    while ((ch = getchar())!='\n'&&ch !=EOF);
}

int main(){

    int qnt; 
    int morePopulationId, moreTouristAttractionsId, moreFieldId, moreGDPId, 
    moreDenselyPopulatedId, moreGDPPerHeadId, moreSuperPowerId,moreTouristAttractions;
    long int morePopulation;
    float moreField, moreGDP, moreDenselyPopulated, refDenselyPopulated, moreGDPPerHead, moreSuperPower;
        
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
        printf("Field: ");
        scanf(" %f", &card[i].fieldValue);
        card[i].denselyPopulated = 
            card[i].populationNumber /
            card[i].fieldValue;
        printf("GDP: ");
        scanf(" %f", &card[i].GDPValue);
        card[i].GDPPerHead = 
            card[i].GDPValue /
            card[i].populationNumber;
        card[i].SuperPower = 
            card[i].populationNumber + 
            card[i].touristAttractionsNumber + 
            card[i].fieldValue + 
            card[i].GDPValue + 
            card[i].GDPPerHead -
            card[i].denselyPopulated;
        bufferClean();
        printf("Card Code (Only char): ");
        fgets(card[i].cardCode, sizeof(card[i].cardCode), stdin);   
        printf("\n");
    }

    for(int i = 0; i < qnt; i++) { 
        printf("Card %d Result:", i+1);
        printf("\n");
        printf("State: %s\n", card[i].stateName);
        printf("City: %s\n", card[i].cityName);
        printf("Population: %i\n", card[i].populationNumber);
        printf("Number of Tourist Attractions: %i\n", card[i].touristAttractionsNumber);
        printf("Field: %.2f\n", card[i].fieldValue);
        printf("GDP: %.2f km²\n", card[i].GDPValue);
        printf("Card Code: %s\n", card[i].cardCode);
        printf("Densely Populate: %.2f inhab/km²\n", card[i].GDPValue);
        printf("GDP Per Head: %.2f\n", card[i].GDPValue);
        printf("\n");
    } 

    for(int i = 0; i < qnt; i++){
        refDenselyPopulated = card[i].denselyPopulated;

        if(card[i].populationNumber > morePopulation){
            morePopulation = card[i].populationNumber;
            morePopulationId = card[i].id;
        }
        if(card[i].touristAttractionsNumber > moreTouristAttractions){
            moreTouristAttractions = card[i].touristAttractionsNumber;
            moreTouristAttractionsId = card[i].id;
        }
        if(card[i].fieldValue > moreField){
            moreField = card[i].fieldValue;
            moreFieldId = card[i].id;
        }
        if(card[i].GDPValue > moreGDP){
            moreGDP = card[i].GDPValue;
            moreGDPId = card[i].id;
        }
        if(card[i].denselyPopulated < moreDenselyPopulated || card[i].denselyPopulated < refDenselyPopulated){
            moreDenselyPopulated = card[i].denselyPopulated;
            moreDenselyPopulatedId = card[i].id;
        }
        if(card[i].GDPPerHead > moreGDPPerHead){
            moreGDPPerHead = card[i].GDPPerHead;
            moreGDPPerHeadId = card[i].id;
        }
        if(card[i].SuperPower > moreSuperPower){
            moreSuperPower = card[i].SuperPower;
            moreSuperPowerId = card[i].id;
        }
    }

    printf("Cards Comparation");
    printf("\n");
    printf("Population:(%d) Card(%d) WIN!\n", morePopulation, morePopulationId);
    printf("Number of Tourist Attractions:(%d) Card(%d) WIN!\n", moreTouristAttractions, moreTouristAttractionsId);
    printf("Field:(%.2f) Card(%d) WIN!\n", moreField, moreFieldId);
    printf("GDP:(%.2f) Card(%d) WIN!\n", moreGDP, moreGDPId);
    printf("Densely Populate:(%.2f inhab/km²) Card(%d) WIN!\n", moreDenselyPopulated, moreDenselyPopulatedId);
    printf("GDP Per Head:(%.2f) Card(%d) WIN!\n", moreGDPPerHead, moreGDPPerHeadId); 
    printf("MORE SUPER-POWER:(%.2f) Card(%d) WIN!\n", moreSuperPower, moreSuperPowerId);
    return 0;
}