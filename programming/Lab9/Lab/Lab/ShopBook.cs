using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab
{
    class ShopBook : LibraryBook
    {
        public double Price
        {
            get;
            private set;
        }




        public bool Buy()
        {
            if (this.IsAvailible)
            {
                this.Quantity--;
                return true;
            }
            else
            {
                return false;
            }
        }

    }



    //namespace lab9
    //{
    //    public class ShopTicket : Ticket
    //    {
    //        public int ItemsNumber { get; private set; }

    //        private int[] Quantities { get; set; }

    //        private double[] Prices { get; set; }

    //        public ShopTicket()
    //            : base()
    //        {
    //            ItemsNumber = 1;
    //            Quantities = new int[ItemsNumber];
    //            Prices = new double[ItemsNumber];
    //        }

    //        public ShopTicket(DateTime p_date, int p_itemsNumber, string p_shopName = "", string p_destination = "")
    //            : base(p_shopName, p_date, 0, p_destination)
    //        {
    //            if (p_itemsNumber > 0)
    //            {
    //                ItemsNumber = p_itemsNumber;
    //            }
    //            else
    //            {
    //                ItemsNumber = 1;
    //            }

    //            Quantities = new int[ItemsNumber];
    //            Prices = new double[ItemsNumber];

    //            for (int i = 0; i < ItemsNumber; i++)
    //            {
    //                Console.Write("\n Enter {0} item quantity:  ", i + 1);
    //                Quantities[i] = int.Parse(Console.ReadLine());
    //                Console.Write("\n Enter {0} item price:  ", i + 1);
    //                Prices[i] = double.Parse(Console.ReadLine());
    //            }
    //            CalculateTotal();
    //        }

    //        public ShopTicket(ShopTicket p_other)
    //            : this(p_other.Date, p_other.ItemsNumber, p_other.Name, p_other.Destination)
    //        {
    //        }

    //        private void CalculateTotal()
    //        {
    //            TotalBill = 0;
    //            for (int i = 0; i < ItemsNumber; i++)
    //            {
    //                TotalBill += Quantities[i] * Prices[i];
    //            }
    //        }

    //        public override string ToString()
    //        {
    //            string result = "";
    //            if (Name != "")
    //            {
    //                result += string.Format("\n Welcome to \"{0}\"", Name);
    //            }
    //            if (Destination != "")
    //            {
    //                result += string.Format("\n {0}", Destination);
    //            }
    //            for (int i = 0; i < ItemsNumber; i++)
    //            {
    //                result += string.Format("\n {0}:\t{1} x {2:f2} $= {3:f2} $", i + 1, Quantities[i], Prices[i], Quantities[i] * Prices[i]);
    //            }
    //            result += string.Format("\n Total:  {0:f2} $\n", TotalBill);
    //            return result;
    //        }
    //    }
    //}

    //static void Main(string[] args)
    //{
    //    DateTime d = new DateTime(1999, 7, 23);
    //    Ticket t = new Ticket("Gas bill", d, 99.99, "Bad person");
    //    Console.WriteLine(t);
    //    while (!t.IsPaid)
    //    {
    //        t.Pay();
    //        Console.WriteLine(t);
    //    }

    //    ShopTicket st = new ShopTicket(DateTime.Today, 3, "Goods");
    //    Console.WriteLine(st);
    //    while (!st.IsPaid)
    //    {
    //        st.Pay();
    //        Console.WriteLine(st);
    //    }
    //    Console.ReadLine();
    //}

    //" > " + (this.IsAvailible? ("Price: {3}") : ("No prices")) + "\n" +



    //    public virtual void Pay()
    //    {
    //        Console.Write("\n Enter your sum: ");
    //        double payResult = double.Parse(Console.ReadLine());
    //        payResult = this.PayResult(payResult);
    //        if (payResult >= 0)
    //        {
    //            Console.WriteLine("\n Your change is {0:f2} $", payResult);
    //        }
    //        else
    //        {
    //            Console.WriteLine("\n You didn't make it. You need {0:f2} $ more.", -payResult);
    //        }
    //    }
    //}
    //}




}