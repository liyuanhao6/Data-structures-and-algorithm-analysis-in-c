// O( N )

int orginal_algorithm(a,b,c)
{
    int i;
    int ans = 1;
    
    a = a % c;

    for ( i = 0; i < b; i++ )
        ans = ( ans * a ) % c;
        
    return ans;
}