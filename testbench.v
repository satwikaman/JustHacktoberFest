/* Assignment : 2
   Problem No : 1
   Semester : Autumn 2020
   Group No : G10
   Members : Ayudh Saxena & Anmol Harsh */

`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11.09.2020 17:51:57
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

reg  [7:0] a,b;
wire [7:0] sum;
reg cin;
wire cout;

ripple_carry_adder m1(.a(a),.b(b),.sum(sum),.cin(cin),.cout(cout)); // initialization of the ripple carry adder module 
initial
begin
    $monitor("time = %0d, a = %b,b = %b, cin = %b,sum = %b,cout = %b",$time,a,b,cin,sum,cout);
    #10 a = 255; b = 1; cin = 0;
    #10 a = 244; b = 11; cin = 0;
    #10 a = 127; b = 1; cin = 0;
    #10 a = 6; b = 5; cin = 0;
    #10 $finish;
end  
endmodule
