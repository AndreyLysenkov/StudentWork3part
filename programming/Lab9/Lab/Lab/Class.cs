using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab
{
    public class Book
    {

        public class Isbn
        {
            private static char separator = '-';

            public int EanUcc
            {
                get;
                private set;
            }

            public int RegistrationGroup
            {
                get;
                private set;
            }

            public int RegistratorIndex
            {
                get;
                private set;
            }

            public int PublisherIndex
            {
                get;
                private set;
            }

            public int ControlIndex
            {
                get;
                private set;
            }

            public Isbn(int ean_ucc = 978, int registration_group = 3, int registration_index = 16, int publisher_index = 148410, int control_index = 0)
            {
                this.EanUcc = ean_ucc;
                this.RegistrationGroup = registration_group;
                this.RegistratorIndex = registration_index;
                this.PublisherIndex = publisher_index;
                this.ControlIndex = control_index;
            }

            public override string ToString()
            {
                return
                    this.EanUcc.ToString() + separator +
                    this.RegistrationGroup + separator +
                    this.RegistratorIndex + separator +
                    this.PublisherIndex + separator +
                    this.ControlIndex;
            }
        }

        public string Title
        {
            get;
            private set;
        }

        public string Author
        {
            get;
            private set;
        }




    }
}

//public class Ticket
//{
//    private string _name;

//    private double _totalBill;

//    private string _destination;

//    private DateTime _date;


//    public string Destination
//    {
//        get
//        {
//            return _destination;
//        }
//        protected set
//        {
//            _destination = value;
//        }
//    }

//    public DateTime Date
//    {
//        get
//        {
//            return _date;
//        }
//        protected set
//        {
//            _date = value;
//        }
//    }

//    public double TotalBill
//    {
//        get
//        {
//            return _totalBill;
//        }
//        protected set
//        {
//            if (value >= 0)
//            {
//                _totalBill = value;
//            }
//        }
//    }

//    public bool IsPaid { get; protected set; }

//    public Ticket(string p_name, DateTime p_date, double p_totalBill, string p_destination)
//    {
//        Name = p_name;
//        Destination = p_destination;
//        Date = p_date;
//        TotalBill = p_totalBill;
//        IsPaid = false;
//    }

//    public Ticket()
//        : this("", DateTime.Today, 0, "")
//    {
//    }

//    public Ticket(Ticket p_other)
//        : this(p_other.Name, p_other.Date, p_other.TotalBill, p_other.Destination)
//    {
//    }

//    public override string ToString()
//    {
//        string result = string.Format("\n {0}\n {1}\n Destination: {2}\n Total= {3} $\n ", Name, Date, Destination, TotalBill);
//        if (IsPaid)
//        {
//            result = string.Concat(result, "Status: paid\n");
//        }
//        else
//        {
//            result = string.Concat(result, "Status: open\n");
//        }
//        return result;
//    }

//    public virtual double PayResult(double p_money)
//    {
//        if (!IsPaid && p_money >= TotalBill)
//        {
//            IsPaid = true;
//        }
//        p_money -= TotalBill;
//        return p_money;
//    }

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
