// O( 1 )

long double A_Sum( void )
{
    long double sum = 0, num = 1;

    do 
    {
        num /= 4;
        sum += num;
    } while( num > 1e-16 );

    return sum;
}

long double B_Sum( void )
{
    long double sum = 0, num = 1, i = 0;
    long double temp;

    do
    {
        i++;
        num /= 4;
        temp = i * num;
        sum += temp;
    } while ( num > 1e-16 );
    
    return sum;
}

long double C_Sum( void )
{
    long double sum = 0, num = 1, i = 0;
    long double temp;

    do
    {
        i++;
        num /= 4;
        temp = i * i * num;
        sum += temp;
    } while( num > 1e-16 );

    return sum;
}

// O( N )

long double D_Sum( int N )
{
    long double sum = 0, num = 1, i = 0;
    long double temp, iTemp;
    int index;

    do
    {
        i++;
        for ( index = 0, iTemp = i; index < N; index++ )
            iTemp *= i;
        num /= 4;
        temp = iTemp * num;
        sum += temp;
    } while( num > 1e-16 );

    return sum;
}