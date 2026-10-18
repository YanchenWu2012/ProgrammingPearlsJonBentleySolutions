#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

const int N = 4000;         
const int TILE_SIZE = 100;  
typedef int DataType;        

std::string get_tile_filename(int row_block, int col_block) {
    std::ostringstream oss;
    oss << "tile_" << row_block << "_" << col_block << ".bin";
    return oss.str();
}

void transposeMatrix() {
    int num_blocks = N / TILE_SIZE;
    std::vector<DataType> row_buf(N);

    std::ifstream infile("input.bin", std::ios::binary);

    for (int i = 0; i < N; ++i) {
        infile.read(reinterpret_cast<char*>(row_buf.data()), N * sizeof(DataType));
        int r_block = i / TILE_SIZE;

        for (int c_block = 0; c_block < num_blocks; ++c_block) {
            std::string filename = get_tile_filename(r_block, c_block);
            std::ofstream tile_file(filename, std::ios::binary | std::ios::app);
            int start_c = c_block * TILE_SIZE;
            tile_file.write(reinterpret_cast<char*>(&row_buf[start_c]), TILE_SIZE * sizeof(DataType));
        }
    }
    infile.close();

    std::vector<DataType> tile(TILE_SIZE * TILE_SIZE);
    std::vector<DataType> transposed_tile(TILE_SIZE * TILE_SIZE);

    for (int r = 0; r < num_blocks; ++r) {
        for (int c = 0; c < num_blocks; ++c) {
            std::string filename = get_tile_filename(r, c);

            std::ifstream src_file(filename, std::ios::binary);
            src_file.read(reinterpret_cast<char*>(tile.data()), TILE_SIZE * TILE_SIZE * sizeof(DataType));
            src_file.close();

            for (int i = 0; i < TILE_SIZE; ++i) {
                for (int j = 0; j < TILE_SIZE; ++j) {
                    transposed_tile[j * TILE_SIZE + i] = tile[i * TILE_SIZE + j];
                }
            }

            std::ofstream dest_file(filename, std::ios::binary);
            dest_file.write(reinterpret_cast<char*>(transposed_tile.data()), TILE_SIZE * TILE_SIZE * sizeof(DataType));
        }
    }

    std::cout << "Matrix transposition completed successfully using small sequential files under 1 MB of RAM!" << std::endl;
}

int main() {
    transposeMatrix();
    return 0;
}
