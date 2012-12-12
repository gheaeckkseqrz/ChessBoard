// Pierre WILMOT
// 06 jiullet 2010
// Chess
// utils.c
// 

void conversion (int source, char *destination)
{

switch (source) 
	{
		case 0:
			*destination = '0';
		break;
		case 1:
			*destination = '1';
		break;
		case 2:
			*destination = '2';
		break;
		case 3:
			*destination = '3';
		break;
		case 4:
			*destination = '4';
		break;
		case 5:
			*destination = '5';
		break;
		case 6:
			*destination = '6';
		break;
		case 7:
			*destination = '7';
		break;
		case 8:
			*destination = '8';
		break;
		case 9:
			*destination = '9';
		break;
	}

} // Fin de la fonction conversion

void conversion2 (int source, char *destination)
{
	
		switch (source)
		{
			case 0:
				*destination = 'a';
			break;
			case 1:
				*destination = 'b';
			break;
			case 2:
				*destination = 'c';
			break;
			case 3:
				*destination = 'd';
			break;
			case 4:
				*destination = 'e';
			break;
			case 5:
				*destination = 'f';
			break;
			case 6:
				*destination = 'g';
			break;
			case 7:
				*destination = 'h';
			break;
		}
	
}
