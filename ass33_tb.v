`include "ass33.v"

module tb33();

reg load,rst,clk;
reg [5:0] a,b;
wire [11:0] product;

unsigned_seq_mult_RS m1(.clk(clk),.load(load),.rst(rst),.a(a),.b(b),.product(product));
initial
begin
    a = 57;b= 32;
    clk = 0;
    $monitor("time = %0d,load = %b,rst = %b,a = %d,b = %d,product = %d ,count=%d ",$time,load,rst,a,b,product,m1.count);
    #10 rst = 1;
    #20 rst = 0; load = 1;
    #40 load = 0;
    #220 a = 11; b = 12;
    #40 load = 1;
    #40 load = 0;
    #220 a = 17;b = 0;load = 1;
    #40 load = 0;
    #220 a = 63; b = 62;
    #40 load = 1;
    #40 load = 0;
    #160 load = 0;
    $finish;
end


always 
    #5 clk = !clk;

endmodule
