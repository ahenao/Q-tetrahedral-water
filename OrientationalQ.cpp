// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
	
int main () {
  string line;
  std::string in;
  int i,m,j,k;
  double count=0;
  char name;
  int n;
  double p;
  double size=15.64;
  double pi=3.141516;
  long double col1,col2,col3,col4,col9,col10,col11;
  long double colx,coly,colz;
  long double col5,col6,col7,col8,col12,col13,col14;
  long double rm,sum,nv1,nv2,nv3,nv4,cosine;
  int r1,r2,r3,r4,r12,r22,r32,r42;
  float q;
  double hist[10001],x[129],y[129],z[129];
  double v1[3],v2[3],v3[3],v4[3];
  ifstream myfile ("Qh20a_32_tetra.dat");
//  ifstream myfile2;
  for (n=0;n<10001;n++)
  {
    hist[n]=0;
  }
  if (myfile.is_open())
  {
    getline (myfile,line);
    getline (myfile,line);
    getline (myfile,line);
    getline (myfile,line);
    for (i=1;i<1251;i++)
    {
      cout << "config= " << i << '\n';
      string filename = "PMfm_" + to_string(i) + ".xyz";
      ifstream myfile2(filename);
      for (n=0;n<129;n++)
	{
	  x[n]=0;
	  y[n]=0;
          z[n]=0;
	}
      getline (myfile2,line);
      getline (myfile2,line);
      for (n=1;n<129;n++)
	{
          getline (myfile2,line);
	  std::istringstream aa(line);
          aa >> name >> colx >> coly >> colz;
          x[n]=colx;y[n]=coly;z[n]=colz;
// PBC Folding coordinates back to box corner at 0,0,0
	  x[n] = x[n] - floor(x[n] / size)*size;
	  y[n] = y[n] - floor(y[n] / size)*size;
	  z[n] = z[n] - floor(z[n] / size)*size;
//	  cout << colx << ' ' << coly << ' ' << colz << '\n';
//	  cout << floor(x[n] / size) << ' ' << floor(y[n] / size) << ' ' << floor(z[n] / size) << '\n';
//	  cout << x[n] << ' ' << y[n] << ' ' << z[n] << '\n';
//          cin.get();
          getline (myfile2,line);
          getline (myfile2,line);
	}
      myfile2.close();
      for (j=1;j<129;j++)
      { 
        rm=0;
        sum=0;
        getline (myfile,line);
        std::istringstream ss(line);
        ss >> col1 >> col2 >> col3 >> col4 >> col5 >> col6>> col7 >> col8 >> col9 >> col10 >> col11 >> col12>> col13 >> col14 ;
// Finding Vector 1
        r1=col1;
        r12=col2;
        v1[1] = x[r12]-x[r1];
        v1[1] = v1[1] - nearbyint(v1[1] / size)*size;
        v1[2] = y[r12]-y[r1];
        v1[2] = v1[2] - nearbyint(v1[2] / size)*size;
        v1[3] = z[r12]-z[r1];
        v1[3] = v1[3] - nearbyint(v1[3] / size)*size;
//        if (i==1250){
//        cout << r12 << " , " << r1 << '\n';
//        cout << "( "<< x[r12] << ", " << x[r1] << " ) ";
//        cout << "( "<< y[r12] << ", " << y[r1] << " ) ";
//        cout << "( "<< z[r12] << ", " << z[r1] << " ) " << '\n';
//        cout << nearbyint(v1[1] / size) << " " << nearbyint(v1[2] / size) << " " << " " << nearbyint(v1[3] / size) << '\n';
//        cout << v1[1] << " " << v1[2] << " " << " " << v1[3] << '\n';
//        cin.get();}
//        cout << v1[1] << " " << v1[2] << " " << " " << v1[3] << '\n';
        nv1 = sqrt( pow(v1[1],2)+pow(v1[2],2)+pow(v1[3],2) );//norm of v1
        getline (myfile,line);
        std::istringstream se(line);
        se >> col1 >> col2 >> col3 >> col4 >> col5 >> col6>> col7 >> col8 >> col9 >> col10 >> col11 >> col12>> col13 >> col14 ;
// Finding Vector 2
        r2=col1;
        r22=col2;
        v2[1] = x[r22]-x[r2];
        v2[1] = v2[1] - nearbyint(v2[1] / size)*size;
        v2[2] = y[r22]-y[r2];
        v2[2] = v2[2] - nearbyint(v2[2] / size)*size;
        v2[3] = z[r22]-z[r2];
        v2[3] = v2[3] - nearbyint(v2[3] / size)*size;
        nv2 = sqrt( pow(v2[1],2)+pow(v2[2],2)+pow(v2[3],2) );//norm of v2
        getline (myfile,line);
        std::istringstream sf(line);
        sf >> col1 >> col2 >> col3 >> col4 >> col5 >> col6>> col7 >> col8 >> col9 >> col10 >> col11 >> col12>> col13 >> col14 ;
// Finding Vector 3
        r3=col1;
        r32=col2;
        v3[1] = x[r32]-x[r3];
        v3[1] = v3[1] - nearbyint(v3[1] / size)*size;
        v3[2] = y[r32]-y[r3];
        v3[2] = v3[2] - nearbyint(v3[2] / size)*size;
        v3[3] = z[r32]-z[r3];
        v3[3] = v3[3] - nearbyint(v3[3] / size)*size;
        nv3 = sqrt( pow(v3[1],2)+pow(v3[2],2)+pow(v3[3],2) );//norm of v3
        getline (myfile,line);
        std::istringstream sg(line);
        sg >> col1 >> col2 >> col3 >> col4 >> col5 >> col6>> col7 >> col8 >> col9 >> col10 >> col11 >> col12>> col13 >> col14 ;
// Finding Vector 4
        r4=col1;
        r42=col2;
        v4[1] = x[r42]-x[r4];
        v4[1] = v4[1] - nearbyint(v4[1] / size)*size;
        v4[2] = y[r42]-y[r4];
        v4[2] = v4[2] - nearbyint(v4[2] / size)*size;
        v4[3] = z[r42]-z[r4];
        v4[3] = v4[3] - nearbyint(v4[3] / size)*size;
        nv4 = sqrt( pow(v4[1],2)+pow(v4[2],2)+pow(v4[3],2) );//norm of v4
//      Double sum over cosine of angle between neighbours
        sum = 0;
        q = 0;
        cosine = (v1[1]*v2[1]+v1[2]*v2[2]+v1[3]*v2[3])/(nv1*nv2);
//	cout << v1[1] << " " <<  v1[2] << " " << " " << v1[3] << '\n';
//	cout << v2[1] << " " << v2[2] << " " << " " << v3[3] << '\n';
//        cout << acos(cosine)*180/pi << '\n';
//        cin.get();
        sum = sum + pow( (cosine + (1.0/3.0)) , 2);
        cosine = (v1[1]*v3[1]+v1[2]*v3[2]+v1[3]*v3[3])/(nv1*nv3);
        sum = sum + pow( (cosine + (1.0/3.0)) , 2);
        cosine = (v1[1]*v4[1]+v1[2]*v4[2]+v1[3]*v4[3])/(nv1*nv4);
        sum = sum + pow( (cosine + (1.0/3.0)) , 2);
        cosine = (v2[1]*v3[1]+v2[2]*v3[2]+v2[3]*v3[3])/(nv2*nv3);
        sum = sum + pow( (cosine + (1.0/3.0)) , 2);
        cosine = (v2[1]*v4[1]+v2[2]*v4[2]+v2[3]*v4[3])/(nv2*nv4); 
        sum = sum + pow( (cosine + (1.0/3.0)) , 2); 
        cosine = (v3[1]*v4[1]+v3[2]*v4[2]+v3[3]*v4[3])/(nv3*nv4); 
        sum = sum + pow( (cosine + (1.0/3.0)) , 2);   
//      Now the q = (1-3/8) * sum
        q = 1.0 - ((3.0/8.0)*sum);//rescaled
//        q = ((3.0/32.0)*sum);//original
//        cout << i << " " << q << ' ' << '\n';
//        cin.get();
        for (n=0;n<10001;n=n+20)
        {
          if (( q > ((n-10.0)/10000.0) ) && ( q < ((n+10.0)/10000.0) )){hist[n]++;count++;}
        }
      }
      cout << '\n';
      getline (myfile,line);
    }
    myfile.close();
  }
  else cout << "Unable to open file"; 
  ofstream outputFile("Qtetrahedral.dat");
        for (n=0;n<10001;n=n+20)
        {
          outputFile <<  n/10000.0 << '\t' << hist[n]/count << '\n';
        }

  return 0;
}

