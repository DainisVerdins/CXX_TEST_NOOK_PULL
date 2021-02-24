

#include "std_lib_facilities.h"
//12
//------------------------------------------------------------------------------
/*
Hre must be discrabe of grammatics
*/

const char number = '8'; //t.kind==number means what t is number
const char quit = 'q';   // t.kind==quit means leksem of quit
const char print = ';';  //means code of printing
const string prompt = "> ";
const string result = "= ";

class Variable
{
public:
    string name;
    double value;
    Variable(string n, double v) : name(n), value(v) {}

private:
};

vector<Variable> var_table;

double get_value(const string &s)
//return value c with name s
{
    for (size_t i = 0; i < var_table.size(); i++)
    {
        if (var_table[i].name == s)
        {
            return var_table[i].value;
        }
    }
    error("get: not known variable ", s);
}
void set_value(string s, double d)
{
    for (size_t i = 0; i < var_table.size(); i++)
    {
        if (var_table[i].name == s)
        {
            var_table[i].value = d;
            return;
        }
    }
    error("set: not known variable ", s);
}

class Token
{
public:
    char kind;     // what kind of token
    double value;  // for numbers: a value
    Token(char ch) // make a Token from a char
        : kind(ch), value(0)
    {
    }
    Token(char ch, double val) // make a Token from a char and a double
        : kind(ch), value(val)
    {
    }
};

//------------------------------------------------------------------------------
class Token_stream
{
public:
    Token_stream();        // make a Token_stream that reads from cin
    Token get();           // get a Token (get() is defined elsewhere)
    void putback(Token t); // put a Token back
    void ignore(char c);

private:
    bool full;    // is there a Token in the buffer?
    Token buffer; // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    : full(false), buffer(0) // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full)
        error("putback() into a full buffer");
    buffer = t;  // copy t to buffer
    full = true; // buffer is now full
}

void Token_stream::ignore(char c)
{
    if (full && c == buffer.kind)
    {
        full = false;
        return;
    }
    full = false;
    char ch = 0;
    while (cin >> ch)
        if (ch == c)
            return;
}

Token Token_stream::get()
{
    if (full)
    { // do we already have a Token ready?
        // remove token from buffer
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch; // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch)
    {
    case print: // for "print"
    case quit:  // for "quit"
    case '!':
    case '%':
    case '{':
    case '}':
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
        return Token(ch); // let each character represent itself
    case '.':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    {
        cin.putback(ch); // put digit back into the input stream
        double val;
        cin >> val;                // read a floating-point number
        return Token(number, val); // let '8' represent "a number"
    }
    default:
        error("Bad token");
        break;
    }
}

//------------------------------------------------------------------------------

Token_stream ts; // provides get() and putback()

//------------------------------------------------------------------------------

double expression(); // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers and parentheses
//deal with unaric + and -
double primary()
{
    Token t = ts.get();
    switch (t.kind)
    {
    case '(': // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')')
        {
            error("')' expected");
            return d;
        }
        break;
    }
    case '{':
    {
        double d = expression();
        t = ts.get();
        if (t.kind != '}')
        {
            error("'}' expected");
            return d;
        }
        break;
    }
    case number:        // we use '8' to represent a number
        return t.value; // return the number's value
    case '-':
        return -primary();
    case '+':
        return primary();
    default:
        error("primary expected");
    }
}

//------------------------------------------------------------------------------

//deal with factorial
double secondary()
{
    double left = primary();
    Token t = ts.get();
    switch (t.kind)
    {
    case '!': // handle of factorial
    {
        // 0!= 1
        double answer = 1;

        //factorial part
        for (size_t i = static_cast<size_t>(left); i > 0; --i)
        {
            answer *= i;
        }
        return answer;
    }
    case number:
        return t.value;

    default:
        ts.putback(t);
        return left;
        // error("secondary expected");
    }
}
// deal with *, /, and %
double term()
{
    double left = secondary();
    Token t = ts.get(); // get the next token from token stream

    while (true)
    {
        switch (t.kind)
        {
        case '*':
            left *= secondary();
            t = ts.get();
            break;
        case '/':
        {
            double d = secondary();
            if (d == 0)
                error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        case '%':
        {
            double d = term();
            int i1 = int(left);
            if (i1 != left)
            {
                error("left operand % is not int");
            }
            int i2 = int(d);
            if (i2 != d)
            {
                error("rigth operand % is not int");
            }
            if (i2 == 0)
            {
                error("% divide on null");
            }

            left = i1 % i2;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t); // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term(); // read and evaluate a Term
    Token t = ts.get();   // get the next token from token stream

    while (true)
    {
        switch (t.kind)
        {
        case '+':
            left += term(); // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term(); // evaluate Term and subtract
            t = ts.get();   //+one logical mistake
            break;
        default:
            ts.putback(t); // put t back into the token stream
            return left;   // finally: no more + or -: return the answer
        }
    }
}

void clean_up_mess()
{
    ts.ignore(print);
}
void calculate()
{
    while (cin)
    {
        try
        {
            cout << prompt; //cal for input
            Token t = ts.get();
            while (t.kind == ';')
                t = ts.get();
            if (t.kind == quit)
            { //q for quite
                keepwindow_open();
                return;
            }
            ts.putback(t);
            cout << result << expression() << '\n';
        }
        catch (const std::exception &e)
        {
            cerr << e.what() << endl;
            clean_up_mess();
        }
    }
}
int main()
{
//NOT DONE AT ALL!!!!
    double val = 0;
    cout << "Welcom into calculator program!" << endl;
    cout << "Please insert expression  \n";
    cout << " you can use these operations +,-,*,/ \n";
    cout << " to get out use 'x' to get result of expression use '" << print << "' \n";

    try
    {
        calculate();
        keepwindow_open();
        return 0;
    }
    catch (runtime_error &e)
    {
        cerr << e.what() << '\n';
        cout << "To close window use ~\n";
        char ch;
        while (cin >> ch)
        {
            if (ch == '~')
                return 1;
        }
    }
    catch (exception &e)
    {
        cerr << "error: " << e.what() << '\n';
        cout << "To close window use ~\n";
        char ch;
        while (cin >> ch)
        {
            if (ch == '~')
                return 1;
        }
        return 1;
    }

    catch (...)
    {
        cerr << "Oops: unknown exception!\n";
        keepwindow_open();
        return 2;
    }
}

//------------------------------------------------------------------------------