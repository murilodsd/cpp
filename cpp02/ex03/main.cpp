#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main(void) {
	// Triângulo com vértices A, B, C
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(5.0f, 10.0f);
    
	std::cout << "Triângulo: A(" << a.getX() << ", " << a.getY()
		  << "), B(" << b.getX() << ", " << b.getY()
		  << "), C(" << c.getX() << ", " << c.getY() << ")" << std::endl << std::endl;
    
	// Pontos para teste
	Point p_inside(5.0f, 2.0f);    // Esperado: Dentro
	Point p_outside_far(20.0f, 20.0f); // Esperado: Fora
	Point p_outside_close(5.0f, -1.0f); // Esperado: Fora
	Point p_on_edge_ab(5.0f, 0.0f);  // Esperado: Fora (na aresta)
	Point p_on_edge_bc(7.5f, 5.0f);  // Esperado: Fora (na aresta BC)
	Point p_on_edge_ca(2.5f, 5.0f);  // Esperado: Fora (na aresta CA)
	Point p_vertex_a(0.0f, 0.0f);    // Esperado: Fora (vértice)
	Point p_vertex_c(5.0f, 10.0f);   // Esperado: Fora (vértice)
    
	Point points_to_test[] = {
	    p_inside, p_outside_far, p_outside_close, p_on_edge_ab,
	    p_on_edge_bc, p_on_edge_ca, p_vertex_a, p_vertex_c
	};
	std::string names[] = {
	    "P_inside(5,2)", "P_outside_far(20,20)", "P_outside_close(5,-1)", "P_on_edge_ab(5,0)",
	    "P_on_edge_bc(7.5,5)", "P_on_edge_ca(2.5,5)", "P_vertex_a(0,0)", "P_vertex_c(5,10)"
	};
    
	for (int i = 0; i < 8; ++i) {
	    std::cout << "Ponto " << names[i] << ": ("
		      << points_to_test[i].getX() << ", " << points_to_test[i].getY() << ") -> "
		      << (bsp(a, b, c, points_to_test[i]) ? "\033[32mDentro\033[0m" : "\033[31mFora\033[0m")
		      << std::endl;
	}
	std::cout << std::endl;
    
	// Teste com triângulo em outra orientação/forma
	Point v1(1.0f, 1.0f);
	Point v2(1.0f, 5.0f);
	Point v3(5.0f, 1.0f);
	Point p_in_v(2.0f, 2.0f); // Dentro
	Point p_out_v(0.5f, 0.5f); // Fora
    
	std::cout << "Triângulo: V1(" << v1.getX() << ", " << v1.getY()
		  << "), V2(" << v2.getX() << ", " << v2.getY()
		  << "), V3(" << v3.getX() << ", " << v3.getY() << ")" << std::endl;
	std::cout << "Ponto P_in_v(2,2): "
		  << (bsp(v1, v2, v3, p_in_v) ? "\033[32mDentro\033[0m" : "\033[31mFora\033[0m") << std::endl;
	std::cout << "Ponto P_out_v(0.5,0.5): "
		  << (bsp(v1, v2, v3, p_out_v) ? "\033[32mDentro\033[0m" : "\033[31mFora\033[0m") << std::endl;
    
    
	return 0;
    }