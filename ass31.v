`timescale 1ns/1ps


//half adder
module ha(a,b,sum,cout);
input a,b;
output sum,cout;

assign sum=a^b;
assign cout=a&b;

endmodule


//full adder using 2 half adders
module fa(a,b,cin,sum,cout);
input a,b,cin;
output sum,cout;
wire t1,t2,t3;

ha hf1(a,b,t1,t2);					//cascading half adders
ha hf2(cin,t1,sum,t3);				//sum of first half adder into input of 2nd half adder
assign cout=t3|t2;					//calculating total cout
endmodule


//1x1 multiplier
module mult1x1(a,b,p);
input a,b;
output p;
assign p=a&b;				//simple multiplication using 'and' implementation

endmodule


//3x1 multiplier using 1x1 multipliers
module mult3x1(a,b,p);
input [2:0]a;					//3-bit
input b; 						//1-bit
output [2:0]p;

mult1x1 m3x10(a[0],b,p[0]);
mult1x1 m3x11(a[1],b,p[1]);
mult1x1 m3x12(a[2],b,p[2]);

endmodule


// 3x3 multiplier using 
module mult3x3(a,b,p);
input [2:0]a;
input [2:0]b;
output [5:0]p;

wire [2:0]t0;
wire [2:0]t1;
wire [2:0]t2;

wire c0,c1,c2,c3,c4,c5,c6;
wire s1,s2,s3,s4;

mult3x1 m3x30(a,b[0],t0);
mult3x1 m3x31(a,b[1],t1);
mult3x1 m3x32(a,b[2],t2);

assign p[0]=t0[0];						//p0

ha ha3x30(t0[1],t1[0],p[1],c0);			//p1

ha h1(c0,t0[2],s1,c1);
ha h2(t1[1],t2[0],s2,c2);
ha h3(s1,s2,p[2],c3);					//p2
fa f1(c1,c2,c3,s3,c4);
fa f2(s3,t1[2],t2[1],p[3],c5);			//p3
fa f3(c4,c5,t2[2],p[4],c6); 			//p4

assign p[5]=c6;							//p5

endmodule


//6x3 multiplier using two 3x3 multiplier
//cascaded two 3x3 multipliers
module mult6x3(a,b,p);
input [5:0]a;
input [2:0]b;
output [8:0]p;

wire [5:0]t0;
wire [5:0]t1;
wire c1,c2,c3,c4,c5;

mult3x3 m6x31(.a(a[2:0]),.b(b),.p(t0));
mult3x3 m6x32(.a(a[5:3]),.b(b),.p(t1));

assign p[0]=t0[0];						//p0
assign p[1]=t0[1];						//p1
assign p[2]=t0[2];						//p2

ha h6x31(t0[3],t1[0],p[3],c1);			//p3
fa f6x31(c1,t0[4],t1[1],p[4],c2);		//p4
fa f6x32(c2,t0[5],t1[2],p[5],c3);		//p5
ha h6x32(c3,t1[3],p[6],c4);				//p6
ha h6x33(c4,t1[4],p[7],c5);				//p7

assign p[8]=t1[5]|c5;					//p8

endmodule


//6x6 multiplier using 2 6x3 modules
module unsigned_array_mult(a,b,product);
input [5:0] a;
input [5:0] b;
output [11:0]product;

wire [8:0]t0;
wire [8:0]t1;
wire c1,c2,c3,c4,c5,c6,c7,c8;

mult6x3 m6x61(.a(a), .b(b[2:0]), .p(t0) );
mult6x3 m6x62(.a(a), .b(b[5:3]), .p(t1) );

assign product[0]=t0[0];						//product 0
assign product[1]=t0[1];						//product 1
assign product[2]=t0[2];						//product 2

ha h6x61(t0[3],t1[0],product[3],c1);			//product 3
fa f6x62(c1,t0[4],t1[1],product[4],c2);			//product 4
fa f6x63(c2,t0[5],t1[2],product[5],c3);			//product 5
fa f6x64(c3,t0[6],t1[3],product[6],c4);			//product 6
fa f6x65(c4,t0[7],t1[4],product[7],c5);			//product 7
fa f6x66(c5,t0[8],t1[5],product[8],c6);			//product 8
ha h6x62(t1[6],c6,product[9],c7);				//product 9
ha h6x63(t1[7],c7,product[10],c8);				//product 10

assign product[11]=c8|t1[8];					//product 11

endmodule


