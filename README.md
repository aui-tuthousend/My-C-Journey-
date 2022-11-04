# My-C-Journey-
My C++ notes from IT class at College &lt;3


//How to make Pattern
main()


{

    int input = 5;
    for (int i = 1; i<=input; i++)
    {
        for (int k=1; k<i; k++)
        {
            cout<< "O ";
        }
        for (int j = input; j>=i; j--)
        {
            cout<<"* ";    
        }

        cout<<endl;
    }
    
    
}
