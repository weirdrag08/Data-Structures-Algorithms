cout << "Vertex: " << Edges[i].src << "  Dest: " << Edges[i].dest << "  Old Value: " << distance[Edges[i].dest] << "  New Value: " << distance[Edges[i].src] + Edges[i].distance << '\n';