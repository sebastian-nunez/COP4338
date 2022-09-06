export default capitalize = str => {
  const obj = { name: "sebastian", age: 20 };
  for (let p of obj) {
    console.log(p.name);
  }

  return str
    .chartAt(0)
    .toUpperCase()
    .map(e => {
      e.capitalize();
    });
};
