struct node_one_ptr {
  int Data{};
  node_one_ptr *next{nullptr};
};

void print_list(node_one_ptr *head);
void push_back(node_one_ptr *&head, const int info);
void push_front(node_one_ptr *&head, const int info);
void pop_back(node_one_ptr *&head);
void pop_front(node_one_ptr *&head);
void clear_list(node_one_ptr *&head);
int viewfront(node_one_ptr *head);
int viewback(node_one_ptr *head);
node_one_ptr *insert(node_one_ptr *&head, node_one_ptr *pos, const int value);
node_one_ptr *find(node_one_ptr *head, const int value);