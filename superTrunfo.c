#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 
#include <float.h>
typedef struct{

    char stateName[50], cityName[50], cardCode[5];
    int id, touristAttractionsNumber;
    long int populationNumber;
    double fieldValue, GDPValue, denselyPopulated, GDPPerHead, SuperPower;

} Card;

void bufferClean(void){
    int ch;
    while ((ch = getchar())!='\n'&&ch !=EOF);
}

int main(){

    int qnt; 
    int morePopulationId, moreTouristAttractionsId, moreFieldId, moreGDPId, 
    moreDenselyPopulatedId, moreGDPPerHeadId, moreSuperPowerId,moreTouristAttractions;
    
    long int morePopulation = LONG_MIN;
    double moreField = DBL_MIN;
    double moreGDP = DBL_MIN;
    double moreDenselyPopulated = DBL_MIN;
    double moreGDPPerHead = DBL_MIN;
    double moreSuperPower = DBL_MIN;
        
    printf("Enter Quantity of Cards: ");
    scanf("%d", &qnt);
    bufferClean();
    
    if (qnt <= 0) {
        return 1;
    }

    Card *card =(Card*)malloc(qnt*sizeof(Card));
    if (card == NULL) {
        return 1;
    }
    
    for(int i = 0; i < qnt; i++){
        printf("\n--- Card %d data ---\n", i+1);
        printf("\n");
        card[i].id = i+1;
        printf("State: ");
        scanf(" %49[^\n]", card[i].stateName);  
        printf("City: ");
        scanf(" %49[^\n]", card[i].cityName);
        printf("Population: ");
        scanf(" %ld", &card[i].populationNumber); 
        printf("Number of Tourist Attractions: ");
        scanf(" %d", &card[i].touristAttractionsNumber);
        printf("Field: ");
        scanf(" %lf", &card[i].fieldValue); 
        printf("GDP: ");
        scanf(" %lf", &card[i].GDPValue);

        if (card[i].populationNumber != 0 && card[i].fieldValue != 0.0) {
            card[i].denselyPopulated = (double)card[i].populationNumber / card[i].fieldValue;
        } else {
            card[i].denselyPopulated = 0.0;
        }

        if (card[i].populationNumber != 0) {
            card[i].GDPPerHead = card[i].GDPValue / card[i].populationNumber;
        } else {
            card[i].GDPPerHead = 0.0;
        }

        card[i].SuperPower = card[i].populationNumber + card[i].touristAttractionsNumber +
        card[i].fieldValue + card[i].GDPValue + card[i].GDPPerHead - card[i].denselyPopulated;

        bufferClean();

        printf("Card Code (Only char): ");
        fgets(card[i].cardCode, sizeof(card[i].cardCode), stdin);   
        printf("\n");
    }

    for(int i = 0; i < qnt; i++) { 
        printf("--- Card %d Results ---\n", i+1);
        printf("State: %s\n", card[i].stateName);
        printf("City: %s\n", card[i].cityName);
        printf("Population: %ld\n", card[i].populationNumber);
        printf("Number of Tourist Attractions: %d\n", card[i].touristAttractionsNumber);
        printf("Field: %.2lf km²\n", card[i].fieldValue);
        printf("GDP: %.2lf\n", card[i].GDPValue);
        printf("Card Code: %s\n", card[i].cardCode);
        printf("Densely Populated: %.2lf inhab/km²\n", card[i].denselyPopulated);
        printf("GDP Per Head: %.2lf\n", card[i].GDPPerHead);
        printf("Super Power: %.2lf\n", card[i].SuperPower);
        printf("\n");
    } 

    if (qnt > 0) {
        morePopulation = card[0].populationNumber;
        morePopulationId = card[0].id;

        moreTouristAttractions = card[0].touristAttractionsNumber;
        moreTouristAttractionsId = card[0].id;

        moreField = card[0].fieldValue;
        moreFieldId = card[0].id;

        moreGDP = card[0].GDPValue;
        moreGDPId = card[0].id;

        moreDenselyPopulated = card[0].denselyPopulated;
        moreDenselyPopulatedId = card[0].id;

        moreGDPPerHead = card[0].GDPPerHead;
        moreGDPPerHeadId = card[0].id;

        moreSuperPower = card[0].SuperPower;
        moreSuperPowerId = card[0].id;
    }

    for(int i = 1; i < qnt; i++){

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
        if(card[i].denselyPopulated < moreDenselyPopulated){
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
    if (qnt > 0) {
        printf("Cards Comparation");
        printf("\n");
        printf("Population:(%d) Card(%d) WIN!\n", morePopulation, morePopulationId);
        printf("Number of Tourist Attractions:(%d) Card(%d) WIN!\n", moreTouristAttractions, moreTouristAttractionsId);
        printf("Field:(%.2f) Card(%d) WIN!\n", moreField, moreFieldId);
        printf("GDP:(%.2f) Card(%d) WIN!\n", moreGDP, moreGDPId);
        printf("Densely Populate:(%.2f inhab/km²) Card(%d) WIN!\n", moreDenselyPopulated, moreDenselyPopulatedId);
        printf("GDP Per Head:(%.2f) Card(%d) WIN!\n", moreGDPPerHead, moreGDPPerHeadId); 
        printf("MORE SUPER-POWER:(%.2f) Card(%d) WIN!\n", moreSuperPower, moreSuperPowerId);
    } else {
        return 1;
    }

    free(card); 
    return 0;
}