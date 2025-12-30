void DrawBorder(NULL)
    {
        int size = 3;
        string name = "Program Name, version 1.0", cpr = "(c) 2025", author = "R. Malik";
        string titles [size] = {"" + name, "Copyright: " + cpr, "Author: " + author};
        int rows = 80;

        cout << "\342\225\224";//upper left corner (dbl-line)

        for (int i = 0; i < rows; i++)
            {
            cout<<"\342\225\220";//horizontal (dbl-line)
            }

        cout << "\342\225\227";//upper right corner (dbl-line)
        cout << endl;

        for (int i = 0; i < size; i++)
            {
            cout << "\342\225\221" << titles[i];//vertical (dbl-line)
            double length = titles[i].length() ;

            for(int j = 0; j < (rows-length); j++)
                {
                cout << " ";
                }

            cout << "\342\225\221 "<< endl;//vertical (dbl-line)
            }

        cout << "\342\225\232";//lower left corner (dbl-line)

        for (int i = 0; i < rows; i++)
            {
            cout << "\342\225\220";//horizontal (dbl-line)
            }

        cout << "\342\225\235";//lower right corner (dbl-line)
        cout <<  "\n";
    }
