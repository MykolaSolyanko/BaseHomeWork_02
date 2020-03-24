struct node_one_ptr {
  int Data{};
  node_one_ptr *next{nullptr};
};
//===================================================
bool print_list(node_one_ptr *root);
void push_back(node_one_ptr **root, const int info);
void push_front(node_one_ptr **root, const int info);
void pop_back(node_one_ptr **root);
void pop_front(node_one_ptr **root);
void clear_list(node_one_ptr **root);
int view_front(node_one_ptr *root);
int view_back(node_one_ptr *root);
//===================================================