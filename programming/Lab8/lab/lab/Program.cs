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
            Task1.Run();
            Task2.Run();

            Console.ReadLine();
        }

        static public class Task1
        {

            static public void Run()
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
                WriteLine("   A      B      C      Result");
                for (int i = 0; i < 8; i++)
                {
                    SetOfTwo(i, ref a, ref b, ref c);
                    WriteLine(String.Format("{0,6} {1,6} {2,6} - {3,6}", a, b, c, func(a, b, c)));
                }
            }

        }

        static public class Task2
        {

            public static void Run()
            {
                for (int i = 100; i < 1000; i++)
                {
                    if (IsSatisfy(i))
                    {
                        WriteLine(String.Format(" {0} ", i));
                    }
                }
            }

            static bool IsSatisfy(int numb)
            {
                return (Math.Pow(numb / 10, 2) - (numb % 10)) == numb;
            }


        }
    }
}