#include <stdio.h>

int main()
{
    struct restaurant{
        int quantity;
        int price;
    };

    struct restaurant paratha, vegetable, water;

    printf("Quantity of Paratha: \n");
    scanf("%d",&paratha.quantity);
    printf("Unit Price: \n");
    scanf("%d",&paratha.price);
    printf("Quantity of Vegetable: \n");
    scanf("%d",&vegetable.quantity);
    printf("Unit Price: \n");
    scanf("%d",&vegetable.price);
    printf("Quantity of Mineral Water: \n");
    scanf("%d",&water.quantity);
    printf("Unit Price: \n");
    scanf("%d",&water.price);

    int people;
    printf("Number of People: \n");
    scanf("%d",&people);

    double eachPay = (((paratha.quantity * paratha.price) + (vegetable.quantity * vegetable.price) + (water.quantity * water.price)) / people);
    printf("Individual people will pay: %.2f tk", eachPay);

    return 0;
}