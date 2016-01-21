using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab
{

    public class Program
    {

        public delegate bool BooleanFunction(bool a, bool b, bool c);

        static void WriteLine(string s)
        {
            Console.WriteLine(s);
        }

        static void Main(string[] args)
        {
            WriteLine("Program Lab Walpy");
            Task1();

            Console.ReadLine();
        }

        static void Task1()
        {
            PrintFunction(BoolFunction);
        }

        static bool BoolFunction(bool a, bool b, bool c)
        {
            return (((a == b) == c) || !a);
        }

        static void SetOfTwo(int number, ref bool a, ref bool b, ref bool c)
        {
            a = (number / 4) == 1;
            b = (number / 2 - (number / 4) * 2) == 1;
            c = (number % 2) == 1;
        }

        static void PrintFunction(BooleanFunction func)
        {
            bool a = false, b = false, c = false;
            WriteLine("  A    B    C     Result");
            for (int i = 0; i < 8; i++)
            {
                SetOfTwo(i, ref a, ref b, ref c);
                WriteLine(String.Format("{0} {1} {2} - {3}", a, b, c, func(a, b, c)));
            }
        }

    }
}