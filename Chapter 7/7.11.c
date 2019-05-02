#include <stdio.h>

void clear_input(void);

int main(void)
{
        char status;
        int artichoke, beet, carrot;
        artichoke = beet = carrot = 0;

        printf("ABC Mail Order Grocery\n");
        do {
                printf("Select what you need:\n");
                printf("a. Artichokes           b. Beets\n");
                printf("c. Carrots              q. Quit\n");
                status = getchar();
                clear_input();

                int toAdd;
                switch (status) {
                case 'a':
                case 'b':
                case 'c':
                        printf("Enter the number of pounds: ");
                        while (scanf("%d", &toAdd) != 1 || toAdd < 0) {
                                printf("Try again: ");
                                clear_input();
                        }
                        clear_input();
                        break;
                case 'q':
                        break;
                default:
                        printf("Invalid choice.\n");
                        break;
                }

                switch (status) {
                case 'a':
                        artichoke += toAdd;
                        break;
                case 'b':
                        beet += toAdd;
                        break;
                case 'c':
                        carrot += toAdd;
                        break;
                }
        } while (status != 'q');

        const double ARTICHOKE_PRICE = 2.05, BEET_PRICE = 1.15, CARROT_PRICE =
                        1.09, DISCOUNT_RATE = .05, DISCOUNT_MIN = 100,
                        SHIPPING1 = 6.50, SHIPPING1_MAX = 5, SHIPPING2 = 14,
                        SHIPPING2_MAX = 20, SHIPPING3_PER_POUND = 0.50;

        int total_pounds = artichoke + beet + carrot;
        double artichoke_cost, beet_cost, carrot_cost, total_cost,
                        discount_availed, shipping_cost, grand_total_cost;

        artichoke_cost = artichoke * ARTICHOKE_PRICE;
        beet_cost = beet * BEET_PRICE;
        carrot_cost = carrot * CARROT_PRICE;
        total_cost = artichoke_cost + beet_cost + carrot_cost;
        if (total_cost > DISCOUNT_MIN)
                discount_availed = total_cost * DISCOUNT_RATE;
        else
                discount_availed = 0;
        if (total_pounds <= SHIPPING1_MAX)
                shipping_cost = SHIPPING1;
        else {
                shipping_cost = SHIPPING2;
                if (total_pounds > SHIPPING2_MAX) {
                        shipping_cost += (total_pounds - SHIPPING2_MAX)
                                        * SHIPPING3_PER_POUND;
                }
        }
        grand_total_cost = total_cost - discount_availed + shipping_cost;

        printf("       ABC Mail Order Grocery\n");
        printf("------------------------------------\n");
        printf("Item            Pounds          Cost\n");
        if (artichoke)
                printf("Artichoke       %6d      %8.2f\n", artichoke,
                                artichoke_cost);
        if (beet)
                printf("Beet            %6d      %8.2f\n", beet, beet_cost);
        if (carrot)
                printf("Carrot          %6d      %8.2f\n", carrot, carrot_cost);
        printf("------------------------------------\n");
        printf("Total                       %8.2f\n", total_cost);
        printf("Discounts          %2.0f%%      %8.2f\n", DISCOUNT_RATE * 100,
                        discount_availed);
        printf("Shipping                    %8.2f\n", shipping_cost);
        printf("------------------------------------\n");
        printf("Grand Total                 %8.2f\n", grand_total_cost);

        return 0;
}

void clear_input(void)
{
        while (getchar() != '\n')
                ;
}
