// O( N )

struct Polynomial
{
    int CoeffArray[ MaxDegree + 1 ];
    int HighPower;
};

void Ini_Polynomial( struct Polynomial* poly )
{
    int i;

    for ( i = 0; i <= MaxDegree; i++ )
        poly->CoeffArray[i] = 0;
    poly->HighPower = 0;
}

void Add_Polynomial( const struct Polynomial* poly1, const struct Polynomial* poly2, struct Polynomial* polySum )
{
    int i;

    Ini_Polynomial( polySum );
    for ( i = 0; i <= MaxDegree; i++ )
        polySum->CoeffArray[i] = poly1->CoeffArray[i] + poly2->CoeffArray[i];
    polySum->HighPower = ( poly1->HighPower > poly2->HighPower ) ? poly1->HighPower : poly2->HighPower;
}

void Mult_Polynomial( const struct Polynomial* poly1, const struct Polynomial* poly2, struct Polynomial* polyProd )
{
    int i, j;

    Ini_Polynomial( polyProd );
    for ( i = 0; i <= MaxDegree; i++ )
        for ( j = 0 ; j <= MaxDegree; j++ )
            polyProd->CoeffArray[i+j] += poly1->CoeffArray[i] * poly2->CoeffArray[j];
    polyProd->HighPower = poly1->HighPower * poly2->HighPower;
}

long double Sum( const struct Polynomial* poly, int x )
{
    int i;
    long double sum = 0;

    for ( i = 0; i <= MaxDegree; i++ )
        sum += Pow( x, i ) * poly->CoeffArray[i];

    return sum;
}

long int Pow( int X, int N )
{
    long int temp = 1;

    while ( N > 1 )
    {
        if ( N % 2 )
            temp *= X;
        else
            ;
        temp *= temp;
        N /= 2;
    }
    if ( N )
        return temp * X;
    else
        return 0;
    
}
