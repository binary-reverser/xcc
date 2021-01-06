The compilation process:
1. lexical analysis
   Lexical parses the source files and provides the symbols(ver "getSymbol" function) to the parser.
2. Gramma analysis
* statement: <program> -> <segment><program> | ∑ 
			 <segment> -> KW_EXTERN<type><def> | <type><def>
			 <type> -> KW_INT | KW_CHAR | KW_VOID
			 <def> -> 
3. Semantic analysis
4. Generate assembly files
