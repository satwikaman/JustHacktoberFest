`timescale 1ns/1ps

module unsigned_seq_mult_RS(
    clk,rst,load,a,b,product
    );
input clk,load,rst;
input [5:0] a,b;
output reg [11:0] product;
reg [12:0] temp;
reg [5:0]shift_a,shift_b;
integer count;
reg stop=0;
reg bb;

always @(posedge clk)
begin
	if(rst==1)
	begin
		shift_a=0;
		shift_b=0;
		temp=0;
		product=0;
		count=0;
		stop=0;
	end
	if(load)
	begin
		shift_a=a;
		shift_b=b;
		temp=0;
		product=0;
		count=0;
		stop=0;
	end
	if(stop==0)
	begin
		if(shift_b[count]==1)
		begin
			temp=temp+{shift_a,6'b000000};
		end
		temp=temp>>1;
		product=temp[11:0];
		count=count+1;
		if(count==6)
		begin
			stop=1;
		end
	end
end



endmodule