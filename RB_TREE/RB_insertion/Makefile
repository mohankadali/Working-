CC        = gcc
OPTIONS   = -g  -Wall  
INCLUDES  = -I.
#OBJS      = balance_tree.o dummy_rbt_node.o insert_rbt_node.o rbt_preorder_traversal.o rb_tree_main.o rotate_left.o rotate_right.o
OBJS      = *.c

target : 
	@echo "Building......\n"
	
	${CC} $(OPTIONS) $(INCLUDES) $(OBJS) -o rb_tree

#%.o : %.c
	
#	$(CC) $(OPTONS) $(INCLUDES) -c $*.c

clean:
	-rm -rf *.o
	-rm rb_tree	

	
