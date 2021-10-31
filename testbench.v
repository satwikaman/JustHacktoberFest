/* Assignment : 2
   Problem No : 3 (testbench)
   Semester : Autumn 2020
   Group No : G10
   Members : Ayudh Saxena & Anmol Harsh */

`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 14.09.2020 15:57:49
// Design Name: 
// Module Name: testbench
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module testbench;
reg clk,write,clr;
reg [7:0] a,b;
wire [7:0] sum;
wire cout;
bit_serial_adder m1(.clk(clk),.a(a),.write(write),.clr(clr),.sum(sum),.b(b),.cout(cout));

initial
begin
    clk = 0;
    $monitor("time = %0d,write = %b,clr = %b,stop = %b,a = %b, b = %b,srega = %b, sregb = %b,sum = %b,cout = %b,count = %0d,sumbit = %b",$time,write,clr,m1.stop,a,b,m1.m1.wo,m1.m2.wo,sum,cout,m1.count,m1.sumbit);
    a = 123; b = 145; clr = 1;
    #30 write = 1; clr = 0;
    #20 write = 0;
    #200 clr = 1; 
    #20 a = 16; b = 48; clr = 0;
    #20 write = 1; // shift registers aren't loaded with a and b unless write = 1
    #60 write = 0; // shifting doesn't begin unless write = 0
    
end

always 
    #10 clk = !clk;

endmodule
