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
            int menu = 0;
            do
            {
                WriteLine("Enter task(1-5) or 0 to exit:");
                menu = Convert.ToInt32(Console.ReadLine());
                WriteLine(String.Format("Task #{0}", menu));
                switch (menu)
                {
                    case (1):
                        Task1.Run();
                        break;
                    case (2):
                        Task2.Run();
                        break;
                    case (3):
                        Task3.Run();
                        break;
                    case (4):
                        Task4.Run();
                        break;
                    case (5):
                        Task5.Run();
                        break;
                    default:
                        WriteLine("Wrong menu number");
                        break;
                }
                WriteLine("--- Press 'Enter' ---");
                Console.ReadLine();
            } while (menu != 0);
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

        static public class Task3
        {

            static int[] array1;

            static int[] array2;

            public static void Run()
            {
                WriteLine("Enter array1:");
                EnterArray(ref array1);
                WriteLine("Enter array2:");
                EnterArray(ref array2);
                Int64 numb1 = MakeNumber(array1);
                Int64 numb2 = MakeNumber(array2);
                WriteLine(String.Format("Summ of two numbers is {0}", numb1 + numb2));
            }

            public static int EnterNumb(string message)
            {
                int result = 0;
                do
                {
                    WriteLine(message);
                    result = Convert.ToInt32(Console.ReadLine());
                } while (!IsDigit(result));
                return result;
            }

            static bool IsDigit(int numb)
            {
                return (numb <= 9) && (numb >= 0);
            }

            static void EnterArray(ref int[] array)
            {
                int size = EnterNumb("Enter size of array: ");
                array = new int[size];
                for (int i = 0; i < size; i++)
                {
                    array[i] = EnterNumb(String.Format("Enter {0} element: ", i));
                }
            }

            static Int64 MakeNumber(int[] array, int basis = 10)
            {
                Int64 result = 0;
                Int64 basicPow = 1;
                for (int i = 0; i < array.Length; i++, basicPow *= basis)
                {
                    result += array[i] * basicPow;
                }
                return result;
            }

        }

        static public class Task4
        {
            public static void Run()
            {
                int N = EnterNumb("Enter N :");
                bool isFounded = false;
                for (int i = 0; !isFounded; i++)
                {
                    if (MultiplyArray(NumbToArray(i)) == N)
                    {
                        WriteLine(String.Format("Number is {0} ", i));
                        isFounded = true;
                    }
                }
            }

            public static int[] NumbToArray (Int64 numb, int basis = 10)
            {
                int[] result = new int[0];
                for (int i = 0; numb > 0; i++, numb /= basis)
                {
                    Array.Resize(ref result, i + 1);
                    result[i] = Convert.ToInt32(numb % basis);
                }
                return result;
            }

            public static Int64 MultiplyArray(int[] array)
            {
                Int64 result = 1;
                for (int i = 0; i < array.Length; i++)
                {
                    result *= array[i];
                }
                return result;
            }

            public static int EnterNumb(string message)
            {
                int result = 0;
                WriteLine(message);
                result = Convert.ToInt32(Console.ReadLine());
                return result;
            }
        }

        static public class Task5
        {

            static int[][] matrix;
            static Point size = new Point(0, 0);

            class Point
            {
                int i;
                int j;

                public Point(int _i, int _j)
                {
                    this.i = _i;
                    this.j = _j;
                }

                public int Row
                {
                    get { return i; }
                }

                public int Column
                {
                    get { return j; }
                }
            }

            public static void Run()
            {
                EnterMatrix();
                FindMinColRow();
                Taskb();
            }

            static int EnterNumb()
            {
                return Convert.ToInt32(Console.ReadLine());
            }

            static void EnterArray(ref int[] array, int size)
            {
                array = new int[size];
                for (int i = 0; i < size; i++)
                {
                    WriteLine(String.Format("Enter element #{0} :", i));
                    array[i] = EnterNumb();
                }
            }

            static void EnterMatrix()
            {
                WriteLine("Enter sizes of array (rows x columns): ");
                size = new Point(EnterNumb(), EnterNumb());
                matrix = new int[size.Row][];
                for (int i = 0; i < size.Row; i++)
                {
                    EnterArray(ref matrix[i], size.Column);
                }
            }

            static void FindMinColRow()
            {
                bool[] columns = new bool[size.Column];
                bool[] rows = new bool[size.Row];
                for (int i = 0; i < size.Row; i++)
                {
                    for (int j = 0; j < size.Column; j++)
                    {
                        if (IsMinimal(new Point(i, j)))
                        {
                            columns[j] = true;
                            rows[i] = true;
                        }
                    }
                }
                WriteLine("Rows are: ");
                for (int i = 0; i < size.Row; i++)
                {
                    if (rows[i])
                    {
                        Console.Write("{0}, ", i);
                    }
                }
                WriteLine("Columns are: ");
                for(int i = 0; i < size.Column; i++)
                {
                    if (columns[i])
                    {
                        Console.Write("{0}, ", i);
                    }
                }
            }

            static bool IsMinimal(Point element)
            {
                bool result = true;
                int i = element.Row;
                int j = element.Column;
                int numb = matrix[i][j];
                for (int k = 0; result && k < size.Column; k++)
                {
                    result &= (matrix[k][j] >= numb);
                }
                for (int k = 0; result && k < size.Row; k++)
                {
                    result &= (matrix[i][k] >= numb);
                }
                return result;
            }

            static void Taskb()
            {
                int subMain = FindSumSubMain();
                int main = FindSumMain();
                WriteLine(String.Format("Taskb: minimal is {0}", Math.Min(subMain, main)));
            }

            static int FindSumSubMain()
            {
                int result = 0;
                int length = Math.Min(size.Column, size.Row);
                for (int i = 0; i < length; i++)
                {
                    result += Math.Abs(matrix[i][length - 1 - i]);
                }
                return result;
            }

            static int FindSumMain()
            {
                int result = 0;
                int length = Math.Min(size.Column, size.Row);
                for (int i = 0; i < length; i++)
                {
                    result += Math.Abs(matrix[i][i]);
                }
                return result;
            }

        }
    }
}