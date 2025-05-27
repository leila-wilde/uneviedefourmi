#include <iostream>
#include <vector>
#include <string>

class Anthill {
private:
    std::vector<std::vector<int>> adj_matrix;
    int size;
    std::vector<std::string> room;

public:
    Anthill(int size) : size(size) {
        adj_matrix.resize(size, std::vector<int>(size, 0));
        room.resize(size);
    }

    void add_tunnel(int u, int v) {
        if (0 <= u && u < size && 0 <= v && v < size) {
            adj_matrix[u][v] = 1;
            adj_matrix[v][u] = 1;
        }
    }

    void add_rooms(int vertex, const std::string& data) {
        if (0 <= vertex && vertex < size) {
            room[vertex] = data;
        }
    }

    void print_graph() const {

        std::cout << "Rooms in anthill (vertices):\n";
        for (int vertex = 0; vertex < size; ++vertex) {
            std::cout << "S" << room[vertex] << ": " << vertex << '\n';
        }

        std::cout << "\nTunnels in anthill (edges):\n";
        for (int u = 0; u < size; ++u) {
            for (int v = u + 1; v < size; ++v) {
                if (adj_matrix[u][v] == 1) {
                    std::cout << "S" << room[u] << " (" << u << ") - S" << room[v] << " (" << v << ")\n";
                }
            }
        }

        std::cout << "\nAdjacency Matrix of anthill:\n";
        for (const auto& row : adj_matrix) {
            for (const auto& val : row) {
                std::cout << val << ' ';
            }
            std::cout << '\n';
        }

    }

    void move_ants_algorithm1();

    void move_ant_algorithm2();

    void move_ants_algorithm3();

};

int main() {
    Anthill g(8);
    g.add_rooms(0, "v"); //Sv
    g.add_rooms(1, "1"); //S1
    g.add_rooms(2, "2"); //S2
    g.add_rooms(3, "3"); //S3
    g.add_rooms(4, "4"); //S4
    g.add_rooms(5, "5"); //S5
    g.add_rooms(6, "6"); //S6
    g.add_rooms(7, "d"); //Sd
    g.add_tunnel(0, 1);  // Sv - S1
    g.add_tunnel(1, 2);  // S1 - S2
    g.add_tunnel(1, 3);  // S1 - S3
    g.add_tunnel(2, 4);  // S2 - S4
    g.add_tunnel(3, 4);  // S3 - S4
    g.add_tunnel(4, 5);  // S4 - S5
    g.add_tunnel(4, 6);  // S4 - S6
    g.add_tunnel(5, 7);  // S5 - Sd
    g.add_tunnel(6, 7);  // S6 - Sd

    g.print_graph();

    return 0;
}