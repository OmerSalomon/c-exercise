int AddNumBin(int a, int b)
{
    int sum = 0;
    int mask = 1;
    bool carry = 0;

    for (int i = 0; i < sizeof(int) * 8; i++)
    {
        bool bitA = mask & a;
        bool bitB = mask & b;
        if (bitA && bitB)
        {
            if (carry)
            {
                sum |= mask;
            }
            carry = 1;
        }
        if (bitA ^ bitB)
        {
            if (carry)
            {
                carry = 1;
            }
            else
            {
                sum |= mask;
            }
        } 

        if (!bitA && !bitB && carry)
        {
            sum |= mask;
        }

        mask <<= 1;
    }
    return sum;
}