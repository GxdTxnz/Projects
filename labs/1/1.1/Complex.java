
public class Complex 
	{
		private double re;
		private double im;
		public Complex()
		{
			this.re = 0;
			this.im = 0;
		}

		public Complex(double re, double im)
			{
			this.re = re;
			this.im = im;
			}

		public static Complex plus(Complex c1, Complex c2)
		{
			Complex result = new Complex(c1.re + c2.re, c1.im + c2.im);
			return result;
		}

		public static Complex minus(Complex c1, Complex c2)
		{
			Complex result = new Complex(c1.re - c2.re, c1.im - c2.im);
			return result;
		}

		public double module() 
		{
			double result = Math.sqrt(this.re * this.re + this.im * this.im);
			return result;
		}

		public double arg() 
		{
			double result = 0;
			if(re > 0)
			{
				result = Math.atan(im/re);
			}
        if(re < 0 && im > 0)
        {     
            result = Math.atan(im/re) + Math.PI;
        }
        if(re < 0 && im < 0)
		{    
			result = Math.atan(im/re) - Math.PI;
        }
        return result;
    }
    
    public String toString(){    
        String str;
        if(im != 0)
            str = re + "+" + im + "i";
        else
            str = re +"";
        return str;
    }
}
