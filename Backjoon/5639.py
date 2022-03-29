import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

class Node:
  def __init__(self, value, left, right):
    self.value = value # 값
    self.left = left 
    self.right = right 

class BST() :
  def __init__(self) :
    self.root = None

  def insert(self, value) :

    def insert_value(node, value) :
      if value < node.value :
        if node.left == None :
          node.left = Node(value, None, None)
        else :
          insert_value(node.left, value)
      else :
        if node.right == None :
          node.right = Node(value, None, None)
        else :
          insert_value(node.right, value)
    if self.root == None :
      self.root = Node(value, None, None)
      return 0
    else :
      insert_value(self.root, value)  
      return 0
  
  def order(self) :
    def postorder(node) :
      if node.left != None :
        postorder(node.left)
      if node.right != None :
        postorder(node.right)
      print(node.value)
    postorder(self.root)


tree = BST()
while True :
  try :
    num = int(input())
    tree.insert(num)
  except :
    break
tree.order()

