export default capitalize = (str) => {
    return str.chartAt(0).toUpperCase().map(e => {
        e.capitalize();
    });
}
