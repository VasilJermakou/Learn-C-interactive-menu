/*hw3.c - exercises from S.Prat book - chapter 7, ex 11 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

//TASK11 - prototype function 
double sumVegetablesWeight(double artishokWeight, double beetWeight, double carrotWeight); 									 																					//prototype function
double calcExpences(double totalWeight, double FIRSTWEIGHT, double FIRSTEXPENCES, double SECONDWEIGHT, double SECONDEXPENCES, double THIRDEXPENCES);
void printOneOrderInfo(double vegetableConstPrice, double vegetableOrder, double vegetableWeightCounter, double discount, double sumExpences);	


/*---===VAERPROJECT===--- */


int main (void){
	
	//TASK11

	const double ARTISHOKPRICE = 2.05;
	const double BEETPRICE = 1.15;
	const double CARROTPRICE = 1.09;
	const double DISCOUNT = 0.95;
	const double FIRSTWEIGHT = 5.0;
	const double SECONDWEIGHT = 20.0;
	const double FIRSTEXPENCES = 6.50;
	const double SECONDEXPENCES = 14.00;
	const double THIRDEXPENCES = 0.50;

	char status = 0;
	
	double artishokWeight,
		   beetWeight,
		   carrotWeight,
		   artishokWeightCounter,
		   beetWeightCounter,
		   carrotWeightCounter,
		   totalWeight,
		   totalExpences,
		   artishokOrder,
		   beetOrder,
		   carrotOrder,
		   discountSum;

	artishokWeight = beetWeight = carrotWeight = artishokWeightCounter = beetWeightCounter = carrotWeightCounter = totalWeight = 0;
	totalExpences = artishokOrder = beetOrder = carrotOrder = discountSum = 0;

	printf("\nChoose desire vegetables from MENU (enter \'a\', \'b\', \'c\', or \'q\').\n");
	printf("\n\t\t\t---===MENU===---");
	printf("\n\'a\' - ARTISHOK;");
	printf("\n\'b\' - BEET;");
	printf("\n\'c\' - CARROT;");
	printf("\n\'q\' - SHOW RESULT & EXIT;\n");

	printf("\nEnter Your choise: ");

		while ((scanf("%c", &status)) != 'q')
		{
			if(status == '\n')
				continue;

			if (status == 'q')
				break;
			else
			{
				switch(status)
				{
					case 'a':
						printf("\nEnter weight of vegetables: ");
						scanf("%lf", &artishokWeight);
						if(artishokWeight <= 0)
							printf("\nThe weight should be a positive number!!!\n");
						else
							artishokWeightCounter += artishokWeight;
						break;
					case 'b':
						printf("\nEnter weight of vegetables: ");
						scanf("%lf", &beetWeight);
						if(beetWeight <= 0)
							printf("\nThe weight should be a positive number!!!\n");
						else
							beetWeightCounter += beetWeight;
						break;
					case 'c':
						printf("\nEnter weight of vegetables: ");
						scanf("%lf", &carrotWeight);
						if(carrotWeight <= 0)
							printf("\nThe weight should be a positive number!!!\n");
						else
							carrotWeightCounter += carrotWeight;
						break;
					default:
						printf("\nunexeptable value");
				}
			}

			printf("\nEnter Your choise: ");	
		}

	//counting vagetables total weight
	totalWeight = sumVegetablesWeight(artishokWeightCounter, beetWeightCounter, carrotWeightCounter);
		
	//counting expences for delivery
	totalExpences = calcExpences(totalWeight, FIRSTWEIGHT, FIRSTEXPENCES, SECONDWEIGHT, SECONDEXPENCES, THIRDEXPENCES);

	//counting prices for vegetables & total order
	artishokOrder = artishokWeightCounter * ARTISHOKPRICE;
	beetOrder = beetWeightCounter * BEETPRICE;
	carrotOrder = carrotWeightCounter * CARROTPRICE;
		
	//printing ALL INFO about order

	printf("\n************************************************************************");
	printf("\n");
	printf("\n\t\t*** TOTAL INFORMATION ***\n");

	if(artishokWeight > 0 && beetWeight == 0 && carrotWeight == 0)
	{
		printOneOrderInfo(ARTISHOKPRICE, artishokOrder, artishokWeightCounter, DISCOUNT, totalExpences);

		printf("\n========================================================================");
		printf("\n|FINAL PRICE:\t\t\t\t\t\t\t%.2lf |                                     ", (artishokOrder * DISCOUNT) + totalExpences);
		printf("\n========================================================================");
	}
	else if(beetWeight > 0 && artishokWeight == 0 && carrotWeight == 0)
	{
		printOneOrderInfo(BEETPRICE, beetOrder, beetWeightCounter, DISCOUNT, totalExpences);

		printf("\n========================================================================");
		printf("\n|FINAL PRICE:\t\t\t\t\t\t\t%.2lf |                                     ", (beetOrder * DISCOUNT) + totalExpences);
		printf("\n========================================================================");
	}
	else if(carrotWeight > 0 && artishokWeight == 0 && beetWeight == 0)
	{
		printOneOrderInfo(CARROTPRICE, carrotOrder, carrotWeightCounter, DISCOUNT, totalExpences);

		printf("\n========================================================================");
		printf("\n|FINAL PRICE:\t\t\t\t\t\t\t%.2lf |                                     ", (carrotOrder * DISCOUNT) + totalExpences);
		printf("\n========================================================================");
	}
	else if(artishokWeight > 0 && beetWeight > 0 && carrotWeight == 0)
	{
		printOneOrderInfo(ARTISHOKPRICE, artishokOrder, artishokWeightCounter, DISCOUNT, totalExpences);
		printOneOrderInfo(BEETPRICE, beetOrder, beetWeightCounter, DISCOUNT, totalExpences);

		printf("\n========================================================================");
		printf("\n|FINAL PRICE:\t\t\t\t\t\t\t%.2lf |                                     ", (artishokOrder * DISCOUNT + totalExpences) + (beetOrder * DISCOUNT + totalExpences));
		printf("\n========================================================================");	
	}
	else if(artishokWeight > 0 && carrotWeight > 0 && beetWeight == 0)
	{
		printOneOrderInfo(ARTISHOKPRICE, artishokOrder, artishokWeightCounter, DISCOUNT, totalExpences);
		printOneOrderInfo(CARROTPRICE, carrotOrder, carrotWeightCounter, DISCOUNT, totalExpences);

		printf("\n========================================================================");
		printf("\n|FINAL PRICE:\t\t\t\t\t\t\t%.2lf |                                     ", (artishokOrder * DISCOUNT + totalExpences) + (carrotOrder * DISCOUNT + totalExpences));
		printf("\n========================================================================");
	}
	else if(beetWeight > 0 && carrotWeight > 0 && artishokWeight == 0)
	{
		printOneOrderInfo(BEETPRICE, beetOrder, beetWeightCounter, DISCOUNT, totalExpences);
		printOneOrderInfo(CARROTPRICE, carrotOrder, carrotWeightCounter, DISCOUNT, totalExpences);

		printf("\n========================================================================");
		printf("\n|FINAL PRICE:\t\t\t\t\t\t\t%.2lf |                                     ", (beetOrder * DISCOUNT + totalExpences) + (carrotOrder * DISCOUNT + totalExpences));
		printf("\n========================================================================");
	}
	else
	{
		printOneOrderInfo(ARTISHOKPRICE, artishokOrder, artishokWeightCounter, DISCOUNT, totalExpences);
		printOneOrderInfo(BEETPRICE, beetOrder, beetWeightCounter, DISCOUNT, totalExpences);
		printOneOrderInfo(CARROTPRICE, carrotOrder, carrotWeightCounter, DISCOUNT, totalExpences);

		printf("\n========================================================================");
		printf("\n|FINAL PRICE:\t\t\t\t\t\t\t%.2lf |                                     ", (artishokOrder * DISCOUNT + totalExpences) + (beetOrder * DISCOUNT + totalExpences) + (carrotOrder * DISCOUNT + totalExpences));
		printf("\n========================================================================");
	}
		
	//printf("\n|Total wage of vagitables: %.2lf" totalWage);
	printf("\n");
	printf("\n************************************************************************");

	
	return 0;
}


//Functions definition(TASK11)
//Function that calculate total weight of vegetables
double sumVegetablesWeight(double artishokWeight, double beetWeight, double carrotWeight)
{
	double sumWieght = 0;
	sumWieght = artishokWeight + beetWeight + carrotWeight;

	return sumWieght;
} 



//Function that calculate expences of delivery
double calcExpences(double totalWeight, double FIRSTWEIGHT, double FIRSTEXPENCES, double SECONDWEIGHT, double SECONDEXPENCES, double THIRDEXPENCES)
{
	double result,
		   firstPartWeight,
		   secondPartWeight;

	result = firstPartWeight = secondPartWeight = 0;

	if (totalWeight > 0 && totalWeight < FIRSTWEIGHT)
		{
			result = FIRSTEXPENCES;
		}
		else if (totalWeight >= FIRSTWEIGHT && totalWeight < SECONDWEIGHT)
		{
			result = SECONDEXPENCES;
		}
		else
		{
			secondPartWeight = totalWeight - SECONDWEIGHT;
			firstPartWeight = totalWeight - secondPartWeight;
			result = SECONDEXPENCES + (secondPartWeight * THIRDEXPENCES);
		}

	return result;
}


//Function that printing all information about the order

void printOneOrderInfo(double vegetableConstPrice, double vegetableOrder, double vegetableWeightCounter, double discount , double sumExpences)
{
	if(vegetableConstPrice == 2.05)				//2.05 ARTISHOKPRICE
		printf("\nYou ordered ARTISHOK.");
	else if(vegetableConstPrice == 1.15)		//1.15 BEETSPRICE
		printf("\nYou ordered BEETS.");
	else
		printf("\nYou ordered CARROTS.");

	printf("\nPrice for 1 kilo:\t\t\t\t\t\t%.2lf", vegetableConstPrice);
	printf("\nTotal wage:\t\t\t\t\t\t\t%.2lf", vegetableWeightCounter);
	printf("\nTotal price:\t\t\t\t\t\t\t%.2lf", vegetableOrder);
	printf("\nTotal delivery expences:\t\t\t\t\t%.2lf", sumExpences);
	if(vegetableOrder >= 100)
	{
		printf("\nPrice with discount(5%%):\t\t\t\t\t%.2lf", vegetableOrder * discount);
		printf("\nDiscounted price with delivery expences:\t\t\t%.2lf\n", (vegetableOrder * discount) + sumExpences);
	}
	else
		printf("\nPrice with expences:\t\t\t\t\t\t%.2lf\n", vegetableOrder + sumExpences);
}